package ru.nsu.ccfit.lukin.web;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.*;
import java.nio.ByteBuffer;
import java.nio.channels.Channel;
import java.nio.channels.Selector;
import java.util.*;

public class Node implements Runnable {

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
        }
        UUID uuid;
        byte[] payload;
        Type type;
        Message(UUID uuid, byte[] payload, Type type) {
            this.uuid = uuid;
            this.payload = payload;
            this.type = type;
        }
    }

    private static class Neighbor{
        SocketAddress address;
        Queue<Message> resendQueue = new LinkedList<>();
        boolean confirmed = false;
        long lastIncomingMessageTime = System.currentTimeMillis();
        Neighbor(SocketAddress address) {
            this.address = address;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Neighbor neighbor = (Neighbor) o;
            return address.equals(neighbor.address);
        }

        @Override
        public int hashCode() {
            return address.hashCode();
        }
    }

    private DatagramSocket socket;
    private boolean isRoot;
    private final Neighbor parent;
    private final Set<Neighbor> childrens = new HashSet<>();
    private int receivePercent;
    private long delay = 500;
    private long timeout = 10000;

    public Node(DatagramSocket socket, int receivePercent, SocketAddress parentAddress) {
        this.socket = socket;
        this.receivePercent = receivePercent;
        if (parentAddress != null) {
            this.parent = new Neighbor(parentAddress);
            isRoot = false;
        } else {
            this.parent = null;
            isRoot = true;
        }
    }

    public static void main(String[] args) {
        String usage = "usage: <local port> <receive percent> [<socket ip> <socket port>]";
        try {
            int localPort = Integer.parseInt(args[0]);
            int receivePercent = Integer.parseInt(args[1]);
            int parentPort = Integer.parseInt(args[2]);
            InetSocketAddress parentAddress = new InetSocketAddress(args[3], parentPort);

            DatagramSocket parentDatagramSocket = new DatagramSocket(localPort);
            new Node(parentDatagramSocket,receivePercent, parentAddress).run();
        } catch (IllegalArgumentException e) {
            System.out.println(usage);
            System.err.println("Wrong arguments:");
            System.err.println("\t" + e.getLocalizedMessage());
        } catch (IOException e) {
            System.out.println(usage);
            System.err.println("Can't create socket with socket:");
            System.err.println("\t" + e.getLocalizedMessage());
        }
    }

    @Override
    public void run() {
        Thread readerThread = new Thread() {

        };
        Thread writerThread = new Thread(() -> {
            try {
                ByteBuffer byteBuffer = ByteBuffer.allocate(4096);
                while (!Thread.interrupted()) {
                    synchronized (childrens) {
                        childrens.removeIf((children) -> {
                            if(children.confirmed) {
                                children.resendQueue.poll();
                            } else if ( children.lastIncomingMessageTime > timeout
                                    &&  children.resendQueue.peek().type == Message.Type.Real) {
                                return true;
                            }
                            Message message = children.resendQueue.peek();
                            byteBuffer.putLong(message.uuid.getLeastSignificantBits());
                            byteBuffer.putLong(message.uuid.getMostSignificantBits());
                            byteBuffer.put(message.payload, 0,
                                Math.max(message.payload.length, 4096 - 2 * Long.BYTES));
                            try {
                                socket.send(
                                    new DatagramPacket(byteBuffer.array(),
                                        message.payload.length + 2 * Long.BYTES, children.address));
                            } catch (IOException e) {
                                e.printStackTrace();
                                return true;
                            }
                            return false;
                        });
                    }
                    if (!isRoot) {
                        synchronized (parent) {
                            if (parent.confirmed) {
                                parent.resendQueue.poll();
                            } else if (parent.lastIncomingMessageTime > timeout) {
                                isRoot = true;
                            }
                            Message message = parent.resendQueue.peek();
                            byteBuffer.putLong(message.uuid.getLeastSignificantBits());
                            byteBuffer.putLong(message.uuid.getMostSignificantBits());
                            byteBuffer.put(message.payload, 0,
                                Math.max(message.payload.length, 4096 - 2 * Long.BYTES));
                            try {
                                socket.send(
                                    new DatagramPacket(byteBuffer.array(),
                                        message.payload.length + 2 * Long.BYTES,
                                        parent.address));
                            } catch (IOException e) {
                                e.printStackTrace();
                            }

                        }
                    }
                    Thread.sleep(delay);
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });
        readerThread.start();
        writerThread.start();
        try(BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            while(!Thread.interrupted()) {
                byte[] byteStr = reader.readLine().getBytes();
                synchronized (childrens) {
                    childrens.forEach((children) ->
                            children.resendQueue.add(new Message(UUID.randomUUID(), byteStr, Message.Type.Real)));
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

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
