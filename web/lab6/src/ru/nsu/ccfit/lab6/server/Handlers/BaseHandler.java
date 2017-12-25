package ru.nsu.ccfit.lab6.server.Handlers;

import com.sun.net.httpserver.Headers;
import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;

import java.io.IOException;
import java.net.HttpURLConnection;
import java.nio.charset.StandardCharsets;

abstract class BaseHandler implements HttpHandler {

    static String getRequestBodyAsString(HttpExchange exchange) {
        String bodySizeString = exchange.getRequestHeaders().getFirst("Content-length");
        int bodySize = (bodySizeString != null) ? Integer.valueOf(bodySizeString) : 2048;
        byte[] body = new byte[bodySize];
        try {
            int readBytes = 0;
            int allReadBytes = 0;
            while (allReadBytes < bodySize &&
                    (readBytes = exchange.getRequestBody().read(body, allReadBytes, body.length - allReadBytes)) != -1) {
                allReadBytes += readBytes;
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return new String(body, StandardCharsets.UTF_8);
    }

    static void printInfo(HttpExchange exchange) {
        System.out.print(exchange.getRequestMethod() + " ");
        System.out.println(exchange.getRequestURI());
        Headers headers = exchange.getRequestHeaders();
        for (String header : headers.keySet()) {
            System.out.println(header + " " + headers.getFirst(header));
        }
    }

    @Override
    public void handle(HttpExchange httpExchange) throws IOException {
        try {
            myHandle(httpExchange);
        } catch (Throwable e) {
            try {
                httpExchange.sendResponseHeaders(HttpURLConnection.HTTP_INTERNAL_ERROR, -1);
                httpExchange.close();
            } catch (Throwable ignored) {

            }
        }
    }

    abstract void myHandle(HttpExchange httpExchange) throws Throwable;
}
