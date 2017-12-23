package ru.nsu.ccfit.lab6.server.Handlers;

import com.google.gson.Gson;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;
import com.sun.net.httpserver.HttpExchange;
import ru.nsu.ccfit.lab6.server.UserController;


import java.io.IOException;
import java.net.HttpURLConnection;
import java.nio.charset.StandardCharsets;
import java.util.UUID;

public class LoginHandler extends BaseHandler {

    @Override
    public void myHandle(HttpExchange httpExchange) throws Throwable {
        printInfo(httpExchange);
        if (httpExchange.getRequestMethod().equalsIgnoreCase("POST")) {
            JsonParser parser = new JsonParser();
            JsonObject obj = parser.parse(getRequestBodyAsString(httpExchange)).getAsJsonObject();
            String username = obj.get("username").getAsString();
            if (username == null || UserController.getInstance().isUserExistAndOnline(username)) {
                httpExchange.getResponseHeaders().add("WWW-Authenticate", "Token realm=’Username is already in use'");
                httpExchange.sendResponseHeaders(HttpURLConnection.HTTP_UNAUTHORIZED, -1);
            } else {
                JsonObject responseBody = new JsonObject();
                UUID userUUID = UserController.getInstance().addUser(username);
                UserController.User user = UserController.getInstance().getUser(userUUID);
                responseBody.addProperty("id", user.getId());
                responseBody.addProperty("username", username);
                responseBody.addProperty("online", true);
                responseBody.addProperty("token", userUUID.toString());
                Gson gson = new Gson();
                byte[] responseBodyBytes = gson.toJson(responseBody).getBytes(StandardCharsets.UTF_8);

                httpExchange.getResponseHeaders().add("Content-Type", "application/json");
                httpExchange.sendResponseHeaders(HttpURLConnection.HTTP_OK, responseBodyBytes.length);

                httpExchange.getResponseBody().write(responseBodyBytes);
            }
        }
        else{
            httpExchange.sendResponseHeaders(HttpURLConnection.HTTP_FORBIDDEN, -1);
        }
        httpExchange.close();
    }
}
