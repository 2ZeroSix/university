package ru.nsu.ccfit.lukin;


import java.io.IOException;
import java.lang.management.ManagementFactory;
import java.net.*;
import java.nio.charset.StandardCharsets;
import java.util.HashMap;
import java.util.Map;
public class Main {

    public static void main(String[] args) {
        String msg = ManagementFactory.getRuntimeMXBean().getName();
        Map<String, Long> clients = new HashMap<>();
        int port = 6789;
        final boolean[] updated = {false};
        try (MulticastSocket socket = new MulticastSocket(port)){
            socket.setSoTimeout(1000);
            InetAddress group = InetAddress.getByName(args[0]);
            socket.joinGroup(group);
            DatagramPacket datagramPacket = new DatagramPacket(msg.getBytes(), msg.length(),
                group, port);
            Thread checker = new Thread(()-> {
                while (!Thread.currentThread().isInterrupted()) {
                    try {
                        long time = System.currentTimeMillis();
                        synchronized (clients) {
                            clients.entrySet().removeIf(entry -> time - entry.getValue() > 4000 && (updated[0] = true));
                            if (updated[0]) {
                                System.out.println("count : " + clients.size());
                                clients.forEach((key, value) -> System.out.println(key.split("@")[0]));
                                updated[0] = false;
                            }
                        }
                        Thread.sleep(2000);
                    } catch (InterruptedException e) {
                        return;
                    }
                }
            });
            Thread reader = new Thread(() -> {
                byte[] msgbytes = msg.getBytes();
                byte[] buf = new byte[msgbytes.length];
                DatagramPacket recv = new DatagramPacket(buf, buf.length);
                while (!Thread.currentThread().isInterrupted()) {
                    try {
                        socket.receive(recv);
                        String key = recv.getAddress().getCanonicalHostName() + "@"
                                + new String(recv.getData(), StandardCharsets.UTF_8);
                        Long val = System.currentTimeMillis();
                        synchronized (clients) {
                            if (!clients.containsKey(key))
                                updated[0] = true;
                            clients.put(key, val);
                        }
                    } catch (java.net.SocketTimeoutException ignored) {
                    } catch (IOException e) {
                        e.printStackTrace();
                        Runtime.getRuntime().exit(1);
                    }
                }
            });
            checker.start();
            reader.start();
            while(System.in.available() == 0) {
                Thread.sleep(1000);
                socket.send(datagramPacket);
            }
            socket.leaveGroup(group);
            checker.interrupt();
            reader.interrupt();
            checker.join();
            reader.join();
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}
