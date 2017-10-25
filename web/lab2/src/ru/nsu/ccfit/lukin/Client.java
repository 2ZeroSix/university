package ru.nsu.ccfit.lukin;

import java.io.*;
import java.net.Socket;
import java.net.UnknownHostException;
import java.nio.ByteBuffer;

public class Client {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("usage: <filename> <server address>");
        }
        File file = new File(args[0]);
        try (   InputStream inputStream = new FileInputStream(file);
                Socket socket = new Socket(args[1], 6666);
                OutputStream outputStream = socket.getOutputStream();
                PrintWriter writer = new PrintWriter(outputStream)) {
            {
                ByteBuffer buffer = ByteBuffer.allocate(Long.BYTES);
                buffer.putLong(file.getTotalSpace());
                byte[] nameBytes = file.getName().getBytes();
                outputStream.write(nameBytes);
                outputStream.write('\n');
                outputStream.write(buffer.array());
                outputStream.write('\n');
            }
            byte[] tmp = new byte[8192];
            while(inputStream.available() > 0) {
                int len = inputStream.read(tmp);
                outputStream.write(tmp, 0, len);
            }
        } catch (UnknownHostException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}