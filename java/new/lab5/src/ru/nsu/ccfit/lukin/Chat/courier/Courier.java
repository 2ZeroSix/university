package ru.nsu.ccfit.lukin.Chat.courier;

import ru.nsu.ccfit.lukin.Chat.Message;

/**
 * Created by йцук on 15.06.2017.
 */
public interface Courier {
    void send(Message message) throws CourierException;
    Message receive() throws CourierException;
}
