package ru.nsu.ccfit.lukin.Chat.courier;

import ru.nsu.ccfit.lukin.Chat.Message;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

/**
 * Created by йцук on 15.06.2017.
 */
public class CourierSerializer implements Courier {
    private ObjectInputStream ois;
    private ObjectOutputStream oos;
    public CourierSerializer(Socket socket) throws IOException {
        ois = new ObjectInputStream(socket.getInputStream());
        oos = new ObjectOutputStream((socket.getOutputStream()));
    }

    @Override
    public void send(Message message) throws CourierException {
        try {
            oos.writeObject(message);
        } catch (IOException e) {
            throw new CourierException("Can't send message", e);
        }
    }

    @Override
    public Message receive() throws CourierException {
        try {
            return (Message)ois.readObject();
        } catch (IOException | ClassNotFoundException e) {
            throw new CourierException("Can't receive message", e);
        }
    }
}
