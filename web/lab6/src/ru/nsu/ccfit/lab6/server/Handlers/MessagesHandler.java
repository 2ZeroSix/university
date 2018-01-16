package ru.nsu.ccfit.lab6.server.Handlers;

import com.google.gson.Gson;
import com.google.gson.JsonArray;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;
import com.sun.net.httpserver.HttpExchange;
import ru.nsu.ccfit.lab6.server.MessagesController;


import java.io.IOException;
import java.net.HttpURLConnection;
import java.nio.charset.StandardCharsets;
import java.util.HashMap;
import java.util.Map;

public class MessagesHandler extends BaseHandler {

    private static Map<String, String> queryToMap(String query) {
        Map<String, String> result = new HashMap<>();
        if (query == null) {
            return result;
        }
        for (String param : query.split("&")) {
            String pair[] = param.split("=");
            if (pair.length > 1) {
                result.put(pair[0], pair[1]);
            } else {
                result.put(pair[0], "");
            }
        }
        return result;
    }

    @Override
    public void myHandle(HttpExchange httpExchange) throws Throwable {
        printInfo(httpExchange);
        if (httpExchange.getRequestMethod().equalsIgnoreCase("POST")) {
            JsonParser parser = new JsonParser();
            JsonObject obj = parser.parse(getRequestBodyAsString(httpExchange)).getAsJsonObject();
            String message = obj.get("message").getAsString();
            if (message == null) {
                httpExchange.sendResponseHeaders(HttpURLConnection.HTTP_FORBIDDEN, -1);
            } else {
                JsonObject responseBody = new JsonObject();
                int id = MessagesController.getInstance().addMessage(message, httpExchange.getPrincipal().getUsername());
                responseBody.addProperty("id", id);
                responseBody.addProperty("message", message);
                Gson gson = new Gson();
                byte[] responseBodyBytes = gson.toJson(responseBody).getBytes(StandardCharsets.UTF_8);
                httpExchange.getResponseHeaders().add("Content-Type", "application/json");
                httpExchange.sendResponseHeaders(HttpURLConnection.HTTP_OK, responseBodyBytes.length);
                httpExchange.getResponseBody().write(responseBodyBytes);
            }
        } else if (httpExchange.getRequestMethod().equalsIgnoreCase("GET")) {
            Map<String, String> params = queryToMap(httpExchange.getRequestURI().getQuery());
            int offset = 10;
            int count = 10;
            try {
                if (params != null) {
                    offset = (params.get("offset") == null || params.get("offset").isEmpty()) ? 10 : Integer.valueOf(params.get("offset"));
                    count = (params.get("count") == null || params.get("count").isEmpty()) ? 10 : Integer.valueOf(params.get("count"));
                    if (count > 100) {
                        count = 100;
                    }
                }
                MessagesController.Message[] messages = MessagesController.getInstance().getMessages(offset, count);
                JsonObject responseBody = new JsonObject();
                JsonArray messagesArray = new JsonArray(messages.length);
                for (MessagesController.Message message : messages) {
                    JsonObject messageBody = new JsonObject();
                    messageBody.addProperty("id", message.getId());
                    messageBody.addProperty("message", message.getMessage());
                    messageBody.addProperty("author", message.getAuthor());

                    messagesArray.add(messageBody);
                }
                responseBody.add("messages", messagesArray);
                Gson gson = new Gson();
                byte[] responseBodyBytes = gson.toJson(responseBody).getBytes(StandardCharsets.UTF_8);
                System.out.println(gson.toJson((responseBody)));
                httpExchange.getResponseHeaders().add("Content-Type", "application/json");
                httpExchange.sendResponseHeaders(HttpURLConnection.HTTP_OK, responseBodyBytes.length);
                httpExchange.getResponseBody().write(responseBodyBytes);
            } catch (IndexOutOfBoundsException | IllegalArgumentException  e) {
                httpExchange.sendResponseHeaders(HttpURLConnection.HTTP_BAD_REQUEST, -1);
            }
        } else {
            httpExchange.sendResponseHeaders(HttpURLConnection.HTTP_BAD_METHOD, -1);
        }
        httpExchange.close();
    }
}
