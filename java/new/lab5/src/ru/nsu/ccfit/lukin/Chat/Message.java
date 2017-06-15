package ru.nsu.ccfit.lukin.Chat;

import java.io.Serializable;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by йцук on 15.06.2017.
 */
public class Message implements Serializable {
    private String type;
    private Map<String, String> fields;
    public Message(String type, Map<String, String> fields) {
        this.type = type;
        this.fields = fields;
    }

    public static Message createErrorMessage(String message) {
        Map<String, String> map = new HashMap<>();
        map.put("message", message);
        return new Message("error", map);
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public Map<String, String> getFields() {
        return fields;
    }

    public void setFields(Map<String, String> fields) {
        this.fields = fields;
    }
}
