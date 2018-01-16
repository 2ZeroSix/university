package ru.nsu.ccfit.lab6.server.Handlers;

import com.google.gson.Gson;
import com.google.gson.JsonArray;
import com.google.gson.JsonObject;
import com.sun.net.httpserver.HttpExchange;
import ru.nsu.ccfit.lab6.server.UserController;

import java.io.IOException;
import java.net.HttpURLConnection;
import java.nio.charset.StandardCharsets;

public class UsersHandler extends BaseHandler {
    @Override
    public void myHandle(HttpExchange httpExchange) throws Throwable {

        printInfo(httpExchange);
        if (httpExchange.getRequestMethod().equalsIgnoreCase("GET")) {
            if ("/users".equals(httpExchange.getRequestURI().getPath())) {
                JsonObject responseBody = new JsonObject();
                JsonArray usersArray = new JsonArray();
                for (UserController.User user : UserController.getInstance().getUsers()) {
                    JsonObject userBody = new JsonObject();
                    userBody.addProperty("id", user.getId());
                    userBody.addProperty("username", user.getUsername());
                    userBody.addProperty("online", (user.getOnlineStatus() != null) ? user.getOnlineStatus().toString() : "null");
                    usersArray.add(userBody);
                }
                responseBody.add("users", usersArray);
                Gson gson = new Gson();
                byte[] responseBodyBytes = gson.toJson(responseBody).getBytes(StandardCharsets.UTF_8);
                httpExchange.getResponseHeaders().add("Content-Type", "application/json");
                httpExchange.sendResponseHeaders(HttpURLConnection.HTTP_OK, responseBodyBytes.length);
                httpExchange.getResponseBody().write(responseBodyBytes);
            } else {
                try {
                    int userId = Integer.valueOf(httpExchange.getRequestURI().getPath().substring(7));
                    UserController.User user = UserController.getInstance().getUser(userId);
                    if (user != null) {
                        JsonObject responseBody = new JsonObject();
                        responseBody.addProperty("id", user.getId());
                        responseBody.addProperty("username", user.getUsername());
                        responseBody.addProperty("online", (user.getOnlineStatus() != null) ? user.getOnlineStatus().toString() : "null");
                        Gson gson = new Gson();
                        byte[] responseBodyBytes = gson.toJson(responseBody).getBytes(StandardCharsets.UTF_8);
                        httpExchange.getResponseHeaders().add("Content-Type", "application/json");
                        httpExchange.sendResponseHeaders(HttpURLConnection.HTTP_OK, responseBodyBytes.length);
                        httpExchange.getResponseBody().write(responseBodyBytes);
                    } else {
                        httpExchange.sendResponseHeaders(HttpURLConnection.HTTP_NOT_FOUND, -1);
                    }
                } catch (NumberFormatException | IndexOutOfBoundsException e) {
                    httpExchange.sendResponseHeaders(HttpURLConnection.HTTP_BAD_REQUEST, -1);
                }
            }

        } else {
            httpExchange.sendResponseHeaders(HttpURLConnection.HTTP_BAD_METHOD, -1);
        }
        httpExchange.close();
    }
}
