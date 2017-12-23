package ru.nsu.ccfit.lab6.server;


import java.util.ArrayList;
import java.util.concurrent.atomic.AtomicInteger;

public class MessagesController {
    private static final MessagesController INSTANCE = new MessagesController();
    private ArrayList<Message> messages = new ArrayList<>();
    private AtomicInteger nextMessageID = new AtomicInteger();

    private MessagesController() {
    }

    public static MessagesController getInstance() {
        return INSTANCE;
    }

    public int addMessage(String message, String author) {
        messages.add(new Message(message, author));
        return nextMessageID.get();
    }

    public Message[] getMessages(int offset, int count) {
        if (offset + count > messages.size()) {
            count = messages.size() - offset;
        }
        return messages.subList(offset, offset + count).toArray(new Message[0]);
    }

    public class Message {
        private int id;
        private String message;
        private String author;

        Message(String message, String author) {
            this.message = message;
            this.author = author;
            this.id = nextMessageID.getAndIncrement();
        }

        public int getId() {
            return id;
        }

        public String getMessage() {
            return message;
        }

        public String getAuthor() {
            return author;
        }
    }

}
