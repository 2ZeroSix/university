package ru.nsu.ccfit.lukin.web;

import ru.nsu.ccfit.lukin.web.sockets.MyServerSocket;
import ru.nsu.ccfit.lukin.web.sockets.MySocket;

import java.io.FileOutputStream;
import java.io.IOException;

public class Server {
    public static void main( String[] args )
    {
        try {
            MyServerSocket serverSocket = new MyServerSocket(9000);
            MySocket socket = serverSocket.accept();

            FileOutputStream outputStream = new FileOutputStream("file.jpg");
            byte[] buffer = new byte[20000];
            int fileSize = 0;
            int size;

            while ((size = socket.receive(buffer)) > 0) {
                outputStream.write(buffer, 0, size);
                fileSize += size;
            }
            outputStream.close();
            System.out.println("Received " + fileSize + " bytes");
            socket.send("End".getBytes());

            socket.close();

            serverSocket.close();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}
