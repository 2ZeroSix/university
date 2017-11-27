package ru.nsu.ccfit.lukin.web;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
import java.net.*;
import java.nio.ByteBuffer;
import java.nio.charset.Charset;
import java.util.*;
import java.util.function.Consumer;

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
                    Math.min(this.payload.length, bufferLen - 2 * Long.BYTES - 1)).flip();
        }
    }

    private static class NeighborInfo {
        LinkedList<Message> resendQueue = new LinkedList<>();
        boolean confirmed = false;
        Message lastIncomingMessage;
        long lastIncomingMessageTime = System.currentTimeMillis();
    }

    private DatagramSocket socket;
    private Optional<Map.Entry<InetSocketAddress, NeighborInfo>> parent;
    private final Map<InetSocketAddress, NeighborInfo> childrens = new HashMap<>();
    private int receivePercent;
    private long delay = 500;
    private long timeout = 1000000;

    public Node(DatagramSocket socket, int receivePercent, InetSocketAddress parentAddress) {
        this.socket = socket;
        this.receivePercent = receivePercent;
        if (parentAddress != null) {
            this.parent = Optional.of(new HashMap.SimpleEntry<>(parentAddress, new NeighborInfo()));
            this.parent.get().getValue().resendQueue.add(new Message(UUID.randomUUID(), new byte[0], Message.Type.Join));
        } else {
            this.parent = Optional.empty();
        }
        try {
            socket.setSoTimeout(1000);
        } catch (SocketException e) {
            e.printStackTrace();
        }
    }

    class MessageReader implements Runnable {
        private int bufferLen;
        private Random rnd;
        private ByteBuffer byteBuffer;
        private DatagramPacket packet;
        MessageReader(int bufferLen) {
            this.bufferLen = bufferLen;
            rnd = new Random(System.currentTimeMillis());
            byteBuffer = ByteBuffer.allocate(bufferLen);
            packet = new DatagramPacket(byteBuffer.array(), byteBuffer.array().length);
        }
        NeighborInfo getNeighborInfo(InetSocketAddress address) {
            NeighborInfo neighborInfo;
            synchronized (parent) {
                neighborInfo = parent.map((parent) -> {
                    if (address.equals(parent.getKey()))    return parent.getValue();
                    else                                    return null;
                }).orElse(null);
            }
            synchronized (childrens) {
                if (neighborInfo == null) {
                    if (childrens.containsKey(address)) {
                        neighborInfo = childrens.get(address);
                    } else if (!Thread.currentThread().isInterrupted()){
                        neighborInfo = new Node.NeighborInfo();
                        childrens.put(address, neighborInfo);
                    } else {
                        return null;
                    }
                }
            }
            return neighborInfo;
        }

        void handleConfirm(InetSocketAddress neighborAddress, NeighborInfo neighborInfo, Message message) {
            if (neighborInfo.resendQueue.peek() != null
                    && neighborInfo.resendQueue.peek().uuid.equals(message.uuid)) {
                System.out.println(neighborAddress.toString() + " confirmed");
                synchronized (childrens) {
                    neighborInfo.confirmed = true;
                    if (Thread.currentThread().isInterrupted() &&
                            neighborInfo.resendQueue.peek().type == Node.Message.Type.Exit) {
                        childrens.remove(neighborAddress);
                    }
                }
            }
            neighborInfo.lastIncomingMessage = message;
        }

        void handleReal(InetSocketAddress neighborAddress, NeighborInfo neighborInfo, Message message) {
            if (neighborInfo.lastIncomingMessage != null &&
                    !neighborInfo.lastIncomingMessage.uuid.equals(message.uuid)) {
                System.out.println(neighborAddress.toString() +  " " + new String(message.payload, Charset.forName("UTF-8")));
                neighborInfo.resendQueue.addFirst(new Node.Message(message.uuid, new byte[0], Node.Message.Type.Confirm));
                synchronized (childrens) {
                    childrens.forEach((addr, info) -> {
                        if (!addr.equals(neighborAddress)) {
                            info.resendQueue.add(message);
                        }
                    });
                }
                synchronized (parent) {
                    parent.ifPresent((parent) -> {
                        if (!parent.getKey().equals(neighborAddress)) {
                            parent.getValue().resendQueue.add(message);
                        }
                    });
                }
            }
            neighborInfo.lastIncomingMessage = message;

        }
        void handleExit(InetSocketAddress neighborAddress, NeighborInfo neighborInfo, Message message) {
            neighborInfo.lastIncomingMessage = message;
            synchronized (childrens) {
                if (childrens.remove(neighborAddress) != null) {
                    System.out.println(neighborAddress.toString() + " exit");
                    return;
                }
            }
            synchronized (parent) {
                parent.ifPresent((parent) -> {
                    if (neighborAddress.equals(parent.getKey())) {
                        try {
                            InetSocketAddress newParentaddr = message.decodeExitMessage();
                            System.out.println(neighborAddress.toString() + " exit");
                            Node.this.parent = Optional.of(new HashMap.SimpleEntry<>(newParentaddr,
                                    new Node.NeighborInfo()));
                        } catch (UnknownHostException e) {
                            e.printStackTrace();
                        }
                    }
                });
            }
        }

        void handleJoin(InetSocketAddress neighborAddress, NeighborInfo neighborInfo, Message message) {
            if (neighborInfo.lastIncomingMessage == null /*||
                    neighborInfo.lastIncomingMessage.uuid.equals(message.uuid)*/) {
                System.out.println(neighborAddress.toString() + " joined");
                neighborInfo.resendQueue.addFirst(new Node.Message(message.uuid, new byte[0], Node.Message.Type.Confirm));
                neighborInfo.lastIncomingMessage = message;
            }
        }

        void handleMessage(InetSocketAddress neighborAddress, NeighborInfo neighborInfo, Message message) {
            switch(message.type) {
                case Confirm:
                    handleConfirm(neighborAddress, neighborInfo, message);
                    break;
                case Real:
                    handleReal(neighborAddress, neighborInfo, message);
                    break;
                case Exit:
                    handleExit(neighborAddress, neighborInfo, message);
                    break;
                case Join:
                    handleJoin(neighborAddress, neighborInfo, message);
                    break;
            }
        }

        Message getMessage() throws IOException {
            socket.receive(packet);
            if (100 - receivePercent > rnd.nextInt(100))
                return null;
            try {
                return new Node.Message(byteBuffer, packet.getLength());
            } catch (IllegalArgumentException e) {
                System.err.println("wrong message received: " + e.getLocalizedMessage());
                return null;
            }
        }
        @Override
        public void run() {
            while (!(Thread.currentThread().isInterrupted() && childrens.isEmpty())) {
                byteBuffer.clear();
                try {
                    Message message = getMessage();
                    if (message == null) continue;

                    InetSocketAddress neighborAddress = new InetSocketAddress(packet.getAddress(), packet.getPort());
                    NeighborInfo neighborInfo = getNeighborInfo(neighborAddress);
                    if (neighborInfo == null) continue;

                    neighborInfo.lastIncomingMessageTime = System.currentTimeMillis();
                    handleMessage(neighborAddress, neighborInfo, message);
                } catch (SocketTimeoutException ignore) {

                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
    class MessageWriter implements Runnable {
        private int bufferLen;
        ByteBuffer byteBuffer;
        MessageWriter(int bufferLen) {
            this.bufferLen = bufferLen;
            byteBuffer = ByteBuffer.allocate(bufferLen);
        }
        boolean WriteToNeighbor(Map.Entry<InetSocketAddress, NeighborInfo> neighbor) {
            byteBuffer.clear();
            if (neighbor.getValue().confirmed) {
                neighbor.getValue().resendQueue.poll();
                neighbor.getValue().confirmed = false;
            } else if (System.currentTimeMillis() - neighbor.getValue().lastIncomingMessageTime > timeout
                    && neighbor.getValue().resendQueue.peek() != null
                    && neighbor.getValue().resendQueue.peek().type != Message.Type.Confirm) {
                return true;
            } else if (neighbor.getValue().resendQueue.peek() != null &&
                    neighbor.getValue().lastIncomingMessage != null &&
                    neighbor.getValue().resendQueue.peek().type == Message.Type.Confirm &&
                    !neighbor.getValue().resendQueue.peek().uuid.equals(neighbor.getValue().lastIncomingMessage.uuid)) {
                neighbor.getValue().resendQueue.poll();
            }
            Message message = neighbor.getValue().resendQueue.peek();
            if (message == null) return false;
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

        }
        @Override
        public void run() {
            while (!(Thread.currentThread().isInterrupted() && childrens.isEmpty())) {
                synchronized (childrens) {
                    childrens.entrySet().removeIf(this::WriteToNeighbor);
                }
                synchronized (parent) {
                    parent = parent.filter((parent) -> !WriteToNeighbor(parent));
                }
                try {
                    Thread.sleep(delay);
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }
            }
        }
    }
    private void setShutdownHook() {
        Runtime.getRuntime().addShutdownHook(new Thread(() -> {
            interrupt();
            while(true) {
                try {
                    join();
                    break;
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }));
    }

    public void sendMessage(String str) {
        sendMessage(str.getBytes(Charset.forName("UTF-8")), Message.Type.Real);
    }
    private void sendMessage(byte[] msg, Message.Type type) {
        Message message = new Message(UUID.randomUUID(), msg, type);
        synchronized (childrens) {
            childrens.forEach((childrenAddr, childrenInfo) ->
                    childrenInfo.resendQueue.add(message));
        }
        synchronized (parent) {
            parent.ifPresent((parent) -> parent.getValue().resendQueue.add(message));
        }
    }
    private void sendExit() {
        Consumer<Map.Entry<InetSocketAddress, NeighborInfo>> send = neighbor -> {
            byte[] byteAddress = neighbor.getKey().getAddress().getAddress();
            ByteBuffer byteBuffer = ByteBuffer
                    .allocate(byteAddress.length + Byte.BYTES)
                    .putInt(neighbor.getKey().getPort())
                    .put(byteAddress);
            byteBuffer.flip();
            sendMessage(byteBuffer.array(), Message.Type.Exit);
        };
        synchronized (parent) {
            parent.ifPresent(send);
        }
        synchronized (childrens) {
            if (!childrens.isEmpty()) {
                send.accept(childrens.entrySet().iterator().next());
            }
        }
    }

    @Override
    public void run() {
        setShutdownHook();
        int bufferLen = 4096;
        Thread readerThread = new Thread(new MessageReader(bufferLen));
        Thread writerThread = new Thread(new MessageWriter(bufferLen));
        readerThread.start();
        writerThread.start();
        synchronized (this) {
            try {
                while (!Thread.interrupted())
                    wait();
            } catch (InterruptedException ignored) {}
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


            try (BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in))) {
                String str;
                while ((str = bufferedReader.readLine()) != null) {
                    if (str.length() != 0)
                        node.sendMessage(str);
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
}
