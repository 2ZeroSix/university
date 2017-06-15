package ru.nsu.ccfit.lukin.Chat;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by йцук on 15.06.2017.
 */
public class MessageHandlerFactory {
    private static Map<String, MessageHandler> handlerMap = new HashMap<>();
    public MessageHandler get(String handlerName) {
        return handlerMap.getOrDefault(handlerName, new DefaultMessageHandler());
    }
}
