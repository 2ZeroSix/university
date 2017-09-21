package ru.nsu.ccfit.lukin;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
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
                } catch (InterruptedException e) {
                }
            });
            while (System.in.available() == 0) {
                Socket socket = serverSocket.accept();
                readers.add(new Server(socket));
            }
        } catch (NumberFormatException e) {
            System.err.println(e.getLocalizedMessage());
            System.err.println("usage: <port>");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void run() {
        try (   InputStream inStream= socket.getInputStream();
                /*Reader inReader = new InputStreamReader(inStream);
                BufferedReader bufReader = new BufferedReader(inReader)*/){
            inStream.read(4096);
            FileOutputStream fileOutputStream = new FileOutputStream(bufReader.readLine());
            long size = new Long(bufReader.readLine());
            if (size > (long)2 << 40) {
                System.err.println("File is too big; max size == " + String.valueOf((long)2 << 40));
            }
            long received = 0;
            while (received < size) {
                bufReader.read
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
