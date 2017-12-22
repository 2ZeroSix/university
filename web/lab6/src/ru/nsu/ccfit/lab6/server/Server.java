package ru.nsu.ccfit.lab6.server;

import com.sun.net.httpserver.Authenticator;
import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpPrincipal;
import com.sun.net.httpserver.HttpServer;
import ru.nsu.ccfit.lab6.server.Handlers.LoginHandler;
import ru.nsu.ccfit.lab6.server.Handlers.LogoutHandler;
import ru.nsu.ccfit.lab6.server.Handlers.MessagesHandler;
import ru.nsu.ccfit.lab6.server.Handlers.UsersHandler;

import java.net.InetSocketAddress;
import java.util.UUID;

public class Server {

    public static void main(String[] args) throws Exception {
        HttpServer server = HttpServer.create();
        server.bind(new InetSocketAddress(2132), 0);

        Authenticator authorization = new Authenticator() {
            @Override
            public Result authenticate(HttpExchange httpExchange) {
                String tokenString = httpExchange.getRequestHeaders().getFirst("Authorization");
                if (tokenString != null) {
                    UserController.User user = UserController.getInstance().getUser(UUID.fromString(tokenString));
                    if (user != null && user.isOnline()) {
                        user.setLastRequestTime();
                        return new Success(new HttpPrincipal(user.getUsername(), tokenString));
                    }
                    return new Failure(403);
                }
                return new Failure(401);
            }
        };

        server.createContext("/login", new LoginHandler());
        server.createContext("/messages", new MessagesHandler()).setAuthenticator(authorization);
        server.createContext("/logout", new LogoutHandler()).setAuthenticator(authorization);
        server.createContext("/users", new UsersHandler()).setAuthenticator(authorization);


        //server.setExecutor(null);
        server.start();
        new Thread(() -> {
            while (true) {
                UserController.getInstance().checkTimeoutForUsers();
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    break;
                }
            }
        }).start();
    }


}