package ru.nsu.ccfit.lab6.server.Handlers;

import com.google.gson.Gson;
import com.google.gson.JsonObject;
import com.sun.net.httpserver.HttpExchange;
import ru.nsu.ccfit.lab6.server.UserController;


import java.io.IOException;
import java.net.HttpURLConnection;
import java.nio.charset.StandardCharsets;
import java.util.UUID;

public class LogoutHandler extends BaseHandler {

    @Override
    public void myHandle(HttpExchange httpExchange) throws Throwable {
        printInfo(httpExchange);
        if (httpExchange.getRequestMethod().equalsIgnoreCase("GET")) {
            UserController.getInstance().getUser(UUID.fromString(httpExchange.getPrincipal().getRealm())).logout();
            JsonObject responseBody = new JsonObject();
            responseBody.addProperty("message", "bye!");
            Gson gson = new Gson();
            byte[] responseBodyBytes = gson.toJson(responseBody).getBytes(StandardCharsets.UTF_8);
            httpExchange.getResponseHeaders().add("Content-Type", "application/json");
            httpExchange.sendResponseHeaders(HttpURLConnection.HTTP_OK, responseBodyBytes.length);
            httpExchange.getResponseBody().write(responseBodyBytes);
        } else {
            httpExchange.sendResponseHeaders(HttpURLConnection.HTTP_FORBIDDEN, -1);
        }
        httpExchange.close();
    }
}
