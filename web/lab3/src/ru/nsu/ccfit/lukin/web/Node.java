package ru.nsu.ccfit.lukin.web;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
import java.net.*;
import java.nio.ByteBuffer;
import java.nio.channels.Channel;
import java.nio.channels.Selector;
import java.util.*;
import java.util.function.Function;
import java.util.function.Predicate;

public class Node extends Thread {

    private static class Message {
        enum Type {
            Confirm ((byte)0),
            Real    ((byte)1),
            Exit    ((byte)2),
            Join    ((byte)3);
            byte type;
            Type(byte type) {
                this.type = type;
            }
            static Type getType(byte type) throws IllegalArgumentException {
                switch (type) {
                    case 0:
                        return Confirm;
                    case 1:
                        return Real;
                    case 2:
                        return Exit;
                    case 3:
                        return Join;
                }
                throw new IllegalArgumentException("Wrong type of message" + String.valueOf(type));
            }
        }
        UUID uuid;
        byte[] payload;
        Type type;
        Message(UUID uuid, byte[] payload, Type type) {
            this.uuid = uuid;
            this.payload = payload;
            this.type = type;
        }
        Message(ByteBuffer byteBuffer, int length) throws IllegalArgumentException {
//            byteBuffer.flip();
            if (length < 2 * Long.BYTES + 1)
                throw new IllegalArgumentException("wrong size of message");
            this.uuid = new UUID(byteBuffer.getLong(), byteBuffer.getLong());
            this.type = Type.getType(byteBuffer.get());
            this.payload = new byte[length - 2 * Long.BYTES - 1];
            byteBuffer.get(this.payload);
        }
        private InetSocketAddress decodeExitMessage() throws IllegalArgumentException, UnknownHostException {
            if (type != Type.Exit)
                throw new IllegalArgumentException("Error trying to decode wrong type of message");
            ByteBuffer byteBuffer = ByteBuffer.wrap(payload);
            int port = byteBuffer.getInt();
            byte[] address = new byte[payload.length - Integer.BYTES];
            byteBuffer.get(address);
            return new InetSocketAddress(InetAddress.getByAddress(address), port);
        }

        int len() {
            return payload.length + 2 * Long.BYTES + 1;
        }
        void writeToByteBuffer(ByteBuffer byteBuffer, int bufferLen) {
            byteBuffer.putLong(this.uuid.getLeastSignificantBits())
                .putLong(this.uuid.getMostSignificantBits())
                .put(this.type.type)
                .put(this.payload, 0,
                    Math.min(this.payload.length, bufferLen - 2 * Long.BYTES - 1));
        }
    }

    private static class NeighborInfo {
        Queue<Message> resendQueue = new LinkedList<>();
        boolean confirmed = false;
        Message lastIncomingMessage;
        long lastIncomingMessageTime = System.currentTimeMillis();
    }

    private DatagramSocket socket;
    private boolean isRoot;
    private Map.Entry<InetSocketAddress, NeighborInfo> parent;
    private final Map<InetSocketAddress, NeighborInfo> childrens = new HashMap<>();
    private int receivePercent;
    private long delay = 500;
    private long timeout = 10000;

    public Node(DatagramSocket socket, int receivePercent, InetSocketAddress parentAddress) {
        this.socket = socket;
        this.receivePercent = receivePercent;
        if (parentAddress != null) {
            this.parent = new HashMap.SimpleEntry<>(parentAddress, new NeighborInfo());
            this.parent.getValue().resendQueue.add(new Message(UUID.randomUUID(), new byte[0], Message.Type.Join));
            isRoot = false;
        } else {
            this.parent = null;
            isRoot = true;
        }
        try {
            socket.setSoTimeout(1000);
        } catch (SocketException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        String usage = "usage: <local port> <receive percent> [<socket ip> <socket port>]";
        try {
            int localPort = Integer.parseInt(args[0]);
            int receivePercent = Integer.parseInt(args[1]);
            InetSocketAddress parentAddress = null;
            if (args.length == 4) {
                int parentPort = Integer.parseInt(args[3]);
                parentAddress = new InetSocketAddress(InetAddress.getByName(args[2]), parentPort);
            }
            DatagramSocket datagramSocket = new DatagramSocket(localPort);
            Node node = new Node(datagramSocket,receivePercent, parentAddress);
            node.start();
            Runtime.getRuntime().addShutdownHook(new Thread(() -> {
                node.interrupt();
                while(true) {
                    try {
                        node.join();
                        break;
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }));
            try (BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in))) {
                while (true) {
                    node.sendMessage(bufferedReader.readLine());
                }
            } catch (IOException e) {
                System.err.println("Error while reading");
            }
        } catch (IllegalArgumentException e) {
            System.out.println(usage);
            System.err.println("Wrong arguments:");
            System.err.println("\t" + e.getLocalizedMessage());
            e.printStackTrace();
        } catch (IOException e) {
            System.out.println(usage);
            System.err.println("Can't create socket with socket:");
            System.err.println("\t" + e.getLocalizedMessage());
        }
    }
    public void sendMessage(String str) {
        try {
            sendMessage(str.getBytes("UTF-8"), Message.Type.Real);
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
    }
    private void sendMessage(byte[] msg, Message.Type type) {
        Message message = new Message(UUID.randomUUID(), msg, type);
        synchronized (childrens) {
            childrens.forEach((childrenAddr, childrenInfo) ->
                    childrenInfo.resendQueue.add(message));
        }
        if (!isRoot) {
            synchronized (parent) {
                if (!isRoot) {
                    parent.getValue().resendQueue.add(message);
                }
            }
        }
    }

    private void sendExit() {
        if (!isRoot) {
            synchronized (parent) {
                if (!isRoot) {
                    byte[] byteAddr = parent.getKey().getAddress().getAddress();
                    ByteBuffer byteBuffer = ByteBuffer.allocate(byteAddr.length + Byte.BYTES)
                            .put(byteAddr).putInt(parent.getKey().getPort());
                    sendMessage(byteBuffer.array(), Message.Type.Exit);
                    return;
                }
            }
        }
        synchronized (childrens) {
            if (!childrens.isEmpty()) {
                Map.Entry<InetSocketAddress, NeighborInfo> priorityChildren
                        = childrens.entrySet().iterator().next();
                byte[] byteAddr = priorityChildren.getKey().getAddress().getAddress();
                ByteBuffer byteBuffer = ByteBuffer.allocate(byteAddr.length + Byte.BYTES)
                        .putInt(priorityChildren.getKey().getPort()).put(byteAddr);
                sendMessage(byteBuffer.array(), Message.Type.Exit);
            }
        }
    }

    @Override
    public void run() {
        int bufferLen = 4096;
        Thread readerThread = new Thread(() -> {
            Random rnd = new Random(System.currentTimeMillis());
            ByteBuffer byteBuffer = ByteBuffer.allocate(bufferLen);
            DatagramPacket packet = new DatagramPacket(byteBuffer.array(), byteBuffer.array().length);
            while (!(Thread.currentThread().isInterrupted() && childrens.isEmpty())) {
                byteBuffer.clear();
                try {
                    socket.receive(packet);
                    if (rnd.nextInt(100) < receivePercent)
                        continue;
                    Message message;
                    try {
                        message = new Message(byteBuffer, packet.getLength());
                    } catch (IllegalArgumentException e) {
                        System.err.println("wrong message received: " + e.getLocalizedMessage());
                        continue;
                    }
                    NeighborInfo neighborInfo = null;
                    InetSocketAddress address = new InetSocketAddress(packet.getAddress(), packet.getPort());
                    if (!isRoot) {
                        synchronized (parent) {
                            if (!isRoot) {
                                if (address.equals(parent.getKey())) {
                                    neighborInfo = parent.getValue();
                                }
                            }
                        }
                    }
                    synchronized (childrens) {
                        if (neighborInfo == null) {
                            if (childrens.containsKey(address)) {
                                neighborInfo = childrens.get(address);
                            } else if (!Thread.currentThread().isInterrupted()){
                                neighborInfo = new NeighborInfo();
                                childrens.put(address, neighborInfo);
                            } else {
                                continue;
                            }
                        }
                    }
                    neighborInfo.lastIncomingMessageTime = System.currentTimeMillis();
                    switch(message.type) {
                        case Confirm:
                            if (neighborInfo.resendQueue.peek() != null
                                && neighborInfo.resendQueue.peek().uuid.equals(message.uuid)) {
                                System.out.println("confirmed");
                                synchronized (childrens) {
                                    neighborInfo.confirmed = true;
                                    if (Thread.currentThread().isInterrupted() &&
                                            neighborInfo.resendQueue.peek().type == Message.Type.Exit) {
                                        childrens.remove(address);
                                    }
                                }
                            }
                            neighborInfo.lastIncomingMessage = message;
                            break;
                        case Real:
                            System.out.println(new String(message.payload, "UTF-8"));
                            if (neighborInfo.lastIncomingMessage != null &&
                                !neighborInfo.lastIncomingMessage.uuid.equals(message.uuid)) {
                                neighborInfo.resendQueue.add(new Message(message.uuid, new byte[0], Message.Type.Confirm));
                                synchronized (childrens) {
                                    childrens.forEach((addr, info) -> {
                                        if (!addr.equals(address)) {
                                            info.resendQueue.add(message);
                                        }
                                    });
                                }
                                if (!isRoot) {
                                    synchronized (parent) {
                                        if (!isRoot && !parent.getKey().equals(address)) {
                                            parent.getValue().resendQueue.add(message);
                                        }
                                    }
                                }
                            }
                            neighborInfo.lastIncomingMessage = message;
                            break;
                        case Exit:
                            System.out.println(address.toString() + " eixt");
                            try {
                                InetSocketAddress newParentaddr = message.decodeExitMessage();
                                if (!isRoot) {
                                    synchronized (parent) {
                                        if (!isRoot && address.equals(parent.getKey())) {
                                            parent = new HashMap.SimpleEntry<>(newParentaddr,
                                                            new NeighborInfo());
                                        }
                                    }
                                }
                            } catch (UnknownHostException e) {
                                e.printStackTrace();
                            }
                            neighborInfo.lastIncomingMessage = message;
                            break;
                        case Join:
                            System.out.println(address.toString() + " joined");
                            neighborInfo.resendQueue.add(new Message(message.uuid, new byte[0], Message.Type.Confirm));
                            neighborInfo.lastIncomingMessage = message;
                            break;
                    }
                    packet.getSocketAddress();
                } catch (SocketTimeoutException ignore) {

                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });
        Thread writerThread = new Thread(() -> {
            ByteBuffer byteBuffer = ByteBuffer.allocate(bufferLen);
            Predicate<Map.Entry<InetSocketAddress, NeighborInfo>> neighborWriter = neighbor -> {
                byteBuffer.clear();
                if(neighbor.getValue().confirmed) {
                    neighbor.getValue().resendQueue.poll();
                    neighbor.getValue().confirmed = false;
                } else if ( neighbor.getValue().lastIncomingMessageTime > timeout
                        &&  neighbor.getValue().resendQueue.peek() != null
                        &&  neighbor.getValue().resendQueue.peek().type != Message.Type.Confirm) {
                    return true;
                }
                Message message = neighbor.getValue().resendQueue.peek();
                message.writeToByteBuffer(byteBuffer, bufferLen);
                try {
                    socket.send(
                            new DatagramPacket(byteBuffer.array(),
                                    Math.min(message.len(), bufferLen), neighbor.getKey()));
                } catch (IOException e) {
                    e.printStackTrace();
                    return true;
                }
                return false;
            };
            while (!(Thread.currentThread().isInterrupted() && childrens.isEmpty())) {
                synchronized (childrens) {
                    childrens.entrySet().removeIf(neighborWriter);
                }
                if (!isRoot) {
                    synchronized (parent) {
                        if (!isRoot) {
                            if (neighborWriter.test(parent)) {
                                isRoot = true;
                            }
                        }
                    }
                }
                try {
                    Thread.sleep(delay);
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }
            }
        });
        readerThread.start();
        writerThread.start();
        try {
            synchronized (this) {
                while (!Thread.interrupted())
                    wait();
            }
        } catch (InterruptedException ignored) {
        }
        sendExit();
        readerThread.interrupt();
        writerThread.interrupt();
        try {
            readerThread.join();
            writerThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
