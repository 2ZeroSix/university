package ru.nsu.ccfit.lab6.client;


import com.google.gson.*;
import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.ProtocolException;
import java.net.URL;
import java.nio.charset.StandardCharsets;

public class Client {
    private ConsoleReader consoleReader = new ConsoleReader();
    private String userToken = "";
    private int nextReceivedMessageID = 0;

    public static void main(String[] args) {
        Client client = new Client();
        client.start();
    }


    private void start() {
        try {
            consoleReader.start();
            System.out.println("Введите username:");
            String username = consoleReader.getNextLine();
            if (login(username)) {
                while (true) {
                    try {
                        printMessages(getMessages());
                        while (consoleReader.hasNext()) {
                            String stringLine = consoleReader.getNextLine();
                            if (stringLine.equals("/list")) {
                                printUsers(getUsers());
                            } else if (stringLine.equals("/exit")) {
                                logout();
                                System.exit(0);
                            } else {
                                sendMessage(stringLine);
                            }
                        }
                        Thread.sleep(250);
                    } catch (IOException e) {
                        if (e.getMessage().equals("403")) {
                            System.out.print("Relogin...");
                            if (!login(username)) {
                                System.out.println("Failure");
                                break;
                            }
                            System.out.println("Success");
                        } else {
                            e.printStackTrace();
                        }
                    }
                }
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    private boolean login(String username) throws InterruptedException {
        for (int attempts = 0; attempts < 5; attempts++) {
            try {
                connectWithUsername(username);
                return true;
            } catch (IOException e) {
                if (e.getMessage().equals("This username already in use")) {
                    System.out.println("Введите username:");
                    username = consoleReader.getNextLine();
                } else {
                    e.printStackTrace();
                }
            }
        }
        return false;
    }

    private void printMessages(JsonObject jsonObject) {
        JsonArray arr = null;
        arr = jsonObject.getAsJsonArray("messages");
        for (int i = 0; i < arr.size(); i++) {
            JsonObject obj = arr.get(i).getAsJsonObject();
            String message = obj.get("message").getAsString();
            String author = obj.get("author").getAsString();
            int id = obj.get("id").getAsInt();
            if (id >= nextReceivedMessageID) {
                nextReceivedMessageID = id + 1;
            }
            System.out.println(author + ": " + message);
        }
    }

    private void printUsers(JsonObject jsonObject) {
        System.out.println("User list:");
        JsonArray arr = jsonObject.getAsJsonArray("users");

        for (int i = 0; i < arr.size(); i++) {
            JsonObject obj = arr.get(i).getAsJsonObject();
            String username = obj.get("username").getAsString();
            String online = obj.get("online").getAsString();
            System.out.println(username + ": " + online);
        }

    }

    private JsonObject getUsers() throws IOException {
        try {
            URL url = new URL("http", "localhost", 2132, "/users");
            //System.out.println(url.toString());
            HttpURLConnection connection = (HttpURLConnection) url.openConnection();
            connection.setRequestProperty("Authorization", userToken);
            connection.connect();
            int status = connection.getResponseCode();
            //System.out.println(status);
            if (status == HttpURLConnection.HTTP_OK) {
                return readBody(connection);
            } else if (status == HttpURLConnection.HTTP_UNAUTHORIZED) {
                throw new IOException("403");
            }
        } catch (MalformedURLException | ProtocolException ignored) {
            //newer throw this
        }
        throw new IOException("Some magic");
    }

    private JsonObject readBody(HttpURLConnection connection) throws IOException {
        String bodySizeString = connection.getHeaderField("Content-length");
        int bodySize = (bodySizeString != null) ? Integer.valueOf(bodySizeString) : 2048;
        JsonParser parser = new JsonParser();
        JsonObject responseBody = parser.parse(readBodyString(connection.getInputStream(), bodySize)).getAsJsonObject();
        //System.out.println(responseBody);
        return responseBody;
    }

    private void sendMessage(String message) throws IOException {
        try {
            URL url = new URL("http", "localhost", 2132, "/messages");
            //System.out.println(url.toString());
            HttpURLConnection connection = (HttpURLConnection) url.openConnection();
            connection.setRequestProperty("Authorization", userToken);
            connection.setRequestProperty("Content-Type", "application/json");
            connection.setRequestMethod("POST");
            connection.setDoOutput(true);
            JsonObject requestBody = new JsonObject();
            requestBody.addProperty("message", message);
            Gson gson = new Gson();
            connection.getOutputStream().write(gson.toJson(requestBody).getBytes(StandardCharsets.UTF_8));
            connection.connect();
            int status = connection.getResponseCode();
            //System.out.println(status);
           /* if (status == HttpURLConnection.HTTP_OK) {

                String bodySizeString = connection.getHeaderField("Content-length");
                int bodySize = (bodySizeString != null) ? Integer.valueOf(bodySizeString) : 2048;
                JSONObject responseBody = new JSONObject(readBodyString(connection.getInputStream(), bodySize));
                System.out.println(responseBody);
            }*/
            if (status == HttpURLConnection.HTTP_FORBIDDEN) {
                throw new IOException("403");
            }
        } catch (MalformedURLException | ProtocolException ignored) {
            //newer throw this
        }
    }

    private JsonObject getMessages() throws IOException {
        try {
            URL url = new URL("http", "localhost", 2132, "/messages?offset="
                    + String.valueOf(nextReceivedMessageID) + "&count=50");
            //System.out.println(url.toString());
            HttpURLConnection connection = (HttpURLConnection) url.openConnection();
            connection.setRequestProperty("Authorization", userToken);

            connection.connect();
            int status = connection.getResponseCode();
            //System.out.println(status);
            if (status == HttpURLConnection.HTTP_OK) {
                return readBody(connection);
            } else if (status == HttpURLConnection.HTTP_UNAUTHORIZED) {
                throw new IOException("403");
            }
        } catch (MalformedURLException | ProtocolException ignored) {
            //newer throw this
        }
        throw new IOException("Some magic");
    }

    private String readBodyString(InputStream inputStream, int bodySize) throws IOException {
        byte[] body = new byte[bodySize];
        int readBytes;
        int allReadBytes = 0;
        while (allReadBytes < bodySize &&
                (readBytes = inputStream.read(body, allReadBytes, body.length - allReadBytes)) != -1) {
            allReadBytes += readBytes;
        }
        return new String(body, StandardCharsets.UTF_8);
    }

    private void connectWithUsername(String username) throws IOException {
        try {
            URL url = new URL("http", "localhost", 2132, "/login");
            //System.out.println(url.toString());
            HttpURLConnection connection = (HttpURLConnection) url.openConnection();
            connection.setRequestMethod("POST");
            connection.setRequestProperty("Content-Type", "application/json");
            connection.setDoOutput(true);
            JsonObject requestBody = new JsonObject();
            requestBody.addProperty("username", username);
            connection.getOutputStream().write(requestBody.toString().getBytes(StandardCharsets.UTF_8));
            connection.connect();
            int status = connection.getResponseCode();
            //System.out.println(status);
            if (status == HttpURLConnection.HTTP_OK) {
                userToken = readBody(connection).get("token").getAsString();
            } else if (status == HttpURLConnection.HTTP_UNAUTHORIZED) {
                System.out.println("This username already in use");
                throw new IOException("This username already in use");
            }
        } catch (MalformedURLException | ProtocolException ignored) {
            //newer throw this
        }
    }

    private void logout() {
        try {
            URL url = new URL("http", "localhost", 2132, "/logout");
            HttpURLConnection connection = (HttpURLConnection) url.openConnection();
            connection.setRequestProperty("Authorization", userToken);
            connection.connect();
            int status = connection.getResponseCode();
            if (status == HttpURLConnection.HTTP_OK) {
                System.out.println("success logout");
            } else {
                System.out.println("NOT success logout");
            }
        } catch (IOException ignored) {

        }
    }
}

