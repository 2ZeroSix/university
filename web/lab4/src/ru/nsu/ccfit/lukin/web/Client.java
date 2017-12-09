package ru.nsu.ccfit.lukin.web;

import ru.nsu.ccfit.lukin.web.sockets.MySocket;

import java.io.FileInputStream;
import java.io.IOException;

public class Client {
    public static void main( String[] args )
    {
        try {
            FileInputStream inputStream = new FileInputStream("to_send.jpg");
            MySocket socket = new MySocket("127.0.0.1", 9000);

            byte[] buffer = new byte[10000];
            int fileSize = 0;
            int num;
            while ((num = inputStream.read(buffer)) > 0) {
                fileSize+=num;
                byte tmp[] = new byte[num];
                for (int i = 0; i < num; i++) {
                    tmp[i] = buffer[i];
                }
                socket.send(tmp);
            }
            inputStream.close();
            System.out.println("Sent " + fileSize + " bytes");

            Thread.sleep(5000);
            num = socket.receive(buffer);
            if (num > 0) {
                System.out.println(new String(buffer).substring(0, num));
            }
            socket.close();
        } catch (IOException | InterruptedException ex) {
            ex.printStackTrace();
        }

    }

}
