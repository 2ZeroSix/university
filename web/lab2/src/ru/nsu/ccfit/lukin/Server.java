package ru.nsu.ccfit.lukin;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketTimeoutException;
import java.nio.charset.Charset;
import java.nio.file.FileSystem;
import java.nio.file.FileSystems;
import java.util.LinkedList;
import java.util.List;
import java.nio.ByteBuffer;

public class Server extends Thread {
    private Socket socket;
    private File file;
    private long received = 0;
    private long fileLen = 0;
    private long previousReceived = 0;
    private long startTime = System.currentTimeMillis();
    private long lastCheck = startTime;
    private Server(Socket socket) {
        this.socket = socket;
    }
    public void printProgressInfo() {
        long curTime = System.currentTimeMillis();
        if (file != null)
            System.out.println(
                socket.getInetAddress().getCanonicalHostName()
                + " : " + socket.getLocalPort()
                + " : "+ file.getName()
                + "\nprogress: " + (double) received / fileLen
                + "; current speed: "
                + (received - previousReceived) / (curTime - lastCheck)
                + "; average speed: " + received / (curTime - startTime)
            );
        lastCheck = curTime;
        previousReceived = received;
    }
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("usage: <port>");
            return;
        }
        File file = new File("uploads");
        if (!((file.isDirectory() && file.canWrite()) || file.mkdir())) {
            System.err.println("can't create subdirectory \"uploads\"");
        }
        try {
            int port = new Integer(args[0]);
            ServerSocket serverSocket = new ServerSocket(port);
            List<Server> readers = new LinkedList<>();
            Thread closerUpdater = new Thread(() -> {
                try {
                    while(!Thread.interrupted()) {
                            sleep(3000);
                        synchronized (readers) {
                            readers.removeIf(r -> {
                                r.printProgressInfo();
                                if (r.isAlive())
                                    return false;
                                else {
                                    try {
                                        r.join();
                                    } catch (InterruptedException e) {
                                        Thread.currentThread().interrupt();
                                        return false;
                                    }
                                    return true;
                                }
                            });
                        }
                    }
                } catch (InterruptedException ignore) {
                }
                System.out.println("Interrupted");
                synchronized (readers) {
                    readers.removeIf(thread -> {
                        while (true) {
                            try {
                                thread.interrupt();
                                thread.join();
                                break;
                            } catch (InterruptedException ignore) {
                            }
                        }
                        return true;
                    });
                }
            });
            closerUpdater.start();
            serverSocket.setSoTimeout(3000);
            while (System.in.available() == 0) {
                try {
                    Socket socket = serverSocket.accept();
                    Server reader = new Server(socket);
                    reader.start();
                    readers.add(reader);
                } catch (SocketTimeoutException ignore) {
                }
            }
            closerUpdater.interrupt();
            closerUpdater.join();
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
        try (   InputStream inStream = socket.getInputStream();
                /*Reader inReader = new InputStreamReader(inStream);
                BufferedReader bufReader = new BufferedReader(inReader)*/){
            byte[] tmp = new byte[4096];
            int len = 0;
            while (len < Integer.BYTES) {
                int l = inStream.read(tmp, len, Integer.BYTES - len);
                if (l == -1) throw new IOException();
                len += l;
            }
            int filenameLen = ByteBuffer.allocate(Long.BYTES).put(tmp,0, Integer.BYTES).getInt(0);
            if (filenameLen > 4096) {
                System.err.println("name of file is too long (max 4096 bytes)");
                return;
            }
            len = 0;
            while (len < filenameLen) {
                int l = inStream.read(tmp, len, filenameLen - len);
                if (l == -1) throw new IOException();
                len += l;
            }
            file = FileSystems.getDefault().getPath("uploads").resolve(FileSystems.getDefault().getPath(new String(tmp, 0, filenameLen, "UTF-8")).getFileName()).toFile();
            len = 0;
            while (len < Long.BYTES) {
                int l = inStream.read(tmp, len, Long.BYTES - len);
                if (l == -1) throw new IOException();
                len += l;
            }
            fileLen = ByteBuffer.allocate(Long.BYTES).put(tmp, 0, Long.BYTES).getLong(0);
            if ( !(file.createNewFile() || file.canWrite())) {
                socket.close();
                return;
            }
            try (FileOutputStream fileOutputStream = new FileOutputStream(file)) {
                if (fileLen > 2L << 40) {
                    System.err.println("file size is too big (max 1T)");
                    socket.close();
                    return;
                }
                while (received < fileLen) {
                    len = inStream.read(tmp, 0, 4096);
                    if (isInterrupted() || len == -1) {
                        throw new CloseFileException();
                    }
                    fileOutputStream.write(tmp, 0, len);
                    received += len;
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        } catch (CloseFileException e){
            if (!file.delete()) {
                System.err.println("error while deleting file: " + file.getName());
            }
        } finally {
            try {
                socket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}

class CloseFileException extends Exception {
    public CloseFileException() {
    }

    public CloseFileException(String s) {
        super(s);
    }

    public CloseFileException(String s, Throwable throwable) {
        super(s, throwable);
    }

    public CloseFileException(Throwable throwable) {
        super(throwable);
    }

    public CloseFileException(String s, Throwable throwable, boolean b, boolean b1) {
        super(s, throwable, b, b1);
    }
}