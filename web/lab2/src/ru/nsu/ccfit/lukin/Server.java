package ru.nsu.ccfit.lukin;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.util.LinkedList;
import java.util.List;

public class Server extends Thread {
    private Socket socket;
    private Server(Socket socket) {
        this.socket = socket;
    }
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("usage: <port>");
            return;
        }
        try {
            int port = new Integer(args[0]);
            ServerSocket serverSocket = new ServerSocket(port);
            List<Thread> readers = new LinkedList<>();
            Thread closer = new Thread(() -> {
                try {
                    while(!Thread.interrupted()) {
                            sleep(1000);
                        synchronized (readers) {
                            readers.removeIf(thread -> {
                                if (thread.isAlive())
                                    return false;
                                else {
                                    try {
                                        thread.join();
                                    } catch (InterruptedException e) {
                                        Thread.currentThread().interrupt();
                                        return false;
                                    }
                                    return true;
                                }
                            });
                        }
                    }
                } catch (InterruptedException ignored) {
                } catch (NumberFormatException e) {
                    System.out.println("usage: <port>");
                }
            });
            while (System.in.available() == 0) {
                Socket socket = serverSocket.accept();
                readers.add(new Server(socket));
            }
            closer.interrupt();
            closer.join();
        } catch (NumberFormatException e) {
            System.err.println(e.getLocalizedMessage());
            System.err.println("usage: <port>");
        } catch (IOException e) {
            e.printStackTrace();
        } catch (InterruptedException ignore) {
        }
    }

    @Override
    public void run() {
        try (InputStream inStream= socket.getInputStream()){
            byte[] tmp = new byte[8192];
            int len = inStream.read(tmp);
            String[] strs = new String(tmp, StandardCharsets.UTF_8).split("\\n", 3);
            String fileName = strs[0];
            long fileSize = new Integer(strs[1]);
            try (FileOutputStream fileOutputStream = new FileOutputStream(fileName)) {
                if (fileSize > (long) 2 << 40) {
                    System.err.println("File is too big; max size == " + String.valueOf((long) 2 << 40));
                }
                long received = strs[0].getBytes().length + strs[1].getBytes().length + "\n\n".getBytes().length;
                fileOutputStream.write(tmp, (int)received, len - (int)received);
                while (received < fileSize) {
                    System.out.println("\r");
                    len = inStream.read(tmp);
                    fileOutputStream.write(tmp, 0, len);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
