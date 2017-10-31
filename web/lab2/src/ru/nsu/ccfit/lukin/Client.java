package ru.nsu.ccfit.lukin;

import java.io.*;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.nio.ByteBuffer;

public class Client {
    private static String usage = "usage: <filename> <server address> <server port>";
    public static void main(String[] args) {
        if (args.length != 3) {
            System.out.println(usage);
        }
        File file = new File(args[0]);
        System.out.println(file.getName());
        try (InputStream inputStream = new FileInputStream(file);
             Socket socket = new Socket(InetAddress.getByName(args[1]), Integer.parseInt(args[2]));
             OutputStream outputStream = socket.getOutputStream()) {
            {
                byte[] nameBytes = file.getName().getBytes();
//                System.out.println(new String(nameBytes, "UTF-8"));
                if (nameBytes.length > 4096) {
                    System.err.println("name of file is too long (max 4096 bytes)");
                    return;
                }
                if (file.length() > 2L << 40) {
                    System.err.println("file size is too big (max 1T)");
                    return;
                }
                ByteBuffer buffer = ByteBuffer.allocate(Integer.BYTES);
                buffer.putInt(nameBytes.length);
                outputStream.write(buffer.array());

                outputStream.write(nameBytes);

                buffer = ByteBuffer.allocate(Long.BYTES);
                buffer.putLong(file.length());
                outputStream.write(buffer.array());
                outputStream.flush();
            }
            byte[] tmp = new byte[4096];
            while (inputStream.available() > 0) {
                int len = inputStream.read(tmp);
                outputStream.write(tmp, 0, len);
            }
        } catch (NumberFormatException e) {
            System.err.println("wrong port number format");
            System.out.println(usage);
        } catch (UnknownHostException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}