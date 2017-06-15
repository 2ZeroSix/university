package ru.nsu.ccfit.lukin.Chat.server;

import ru.nsu.ccfit.lukin.Chat.Message;
import ru.nsu.ccfit.lukin.Chat.MessageHandler;
import ru.nsu.ccfit.lukin.Chat.MessageHandlerFactory;
import ru.nsu.ccfit.lukin.Chat.courier.Courier;
import ru.nsu.ccfit.lukin.Chat.courier.CourierException;
import ru.nsu.ccfit.lukin.Chat.courier.CourierSerializer;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.util.*;
import java.util.concurrent.*;

/**
 * Created by йцук on 15.06.2017.
 */
public class Server implements Runnable{
    private class Client {
        private Socket socket;
        private String name = null;
        Client(Socket socket) {
            this.socket = socket;
        }

        synchronized String getName() {
            return name;
        }

        synchronized void setName(String name) {
            this.name = name;
        }

        Socket getSocket() {
            return socket;
        }

    }
    public class Context {
        public Set<Client> getClients() {
            return clients;
        }

        public List<String> getHistory() {
            return history;
        }
        public void addToHistory(String message) {
            synchronized (history) {
                if (history.size() == historyMaxSize) {
                    history.remove(0);
                }
                history.add(message);
            }
        }
    }
    private ServerSocket serverSocket;
    private static final int port = 4321;
    private static final int maxClients = 10;
    private static final int logoutTimeout = 600;
    private static final int historyMaxSize = 100;
    private final Set<Client> clients = new ConcurrentSkipListSet<>();
    private final List<String> history = new ArrayList<>(historyMaxSize);
    public Server() throws IOException {
        serverSocket = new ServerSocket(port);
    }

    @Override
    public void run() {
        BlockingQueue<Runnable> queue = new SynchronousQueue<>();
        ThreadPoolExecutor threadPoolExecutor = new ThreadPoolExecutor(0, maxClients, 10,
                TimeUnit.SECONDS, queue);
        while (!Thread.currentThread().isInterrupted()) {
            try (Socket socket = serverSocket.accept()) {
                Client client = new Client(socket);
                clients.add(client);
                queue.add(() -> listener(client));
            } catch (IOException e) {
                System.err.println("can't open socket: " + e.getLocalizedMessage());
            }
        }
    }

    private void listener(Client client) {
        try {
            client.socket.setSoTimeout(logoutTimeout);
        } catch (SocketException e) {
            e.printStackTrace();
            return;
        }

        Courier courier;
        try {
            courier = new CourierSerializer(client.getSocket());
        } catch (IOException e) {
            System.err.println("Can't create courier" + e.getLocalizedMessage());
            return;
        }

        MessageHandlerFactory factory = new MessageHandlerFactory();

        try {
            String name;
            if ((name = getName(courier)) == null)
                return;
            client.setName(name);
            while(!Thread.currentThread().isInterrupted()) {
                Message message = courier.receive();
                MessageHandler messageHandler = factory.get(message.getType());
            }
        } catch (CourierException e) {
            e.printStackTrace();
            return;
        } finally {
            clients.remove(client);
        }
    }

    private String getName(Courier courier) throws CourierException {
        try {
            Message message = courier.receive();
            if (message.getType().equals("login")) {
                return message.getFields().get("name");
            } else {
                throw new ClassNotFoundException();
            }
        } catch (ClassNotFoundException e) {
            System.err.println("wrong first message" + e.getLocalizedMessage());
            courier.send(Message.createErrorMessage("wrong first message" + e.getLocalizedMessage()));
        } catch (CourierException e) {
            e.printStackTrace();
        }
        return null;
    }
}
