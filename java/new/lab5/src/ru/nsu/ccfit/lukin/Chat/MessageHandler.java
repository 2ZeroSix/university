package ru.nsu.ccfit.lukin.Chat;

import ru.nsu.ccfit.lukin.Chat.courier.CourierException;
import ru.nsu.ccfit.lukin.Chat.server.Server;

/**
 * Created by йцук on 15.06.2017.
 */
public interface MessageHandler {
    void handle(Server.Context context, Message message) throws CourierException;
}
