package ru.nsu.ccfit.lab6.server;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.UUID;
import java.util.concurrent.atomic.AtomicInteger;

public class UserController {

    private static final UserController INSTANCE = new UserController();
    private AtomicInteger atomicInteger = new AtomicInteger();
    private HashMap<UUID, User> users = new HashMap<>();

    private UserController() {
    }

    public static UserController getInstance() {
        return INSTANCE;
    }

    public Collection<User> getUsers() {
        return users.values();
    }

    //    public boolean isUserExist(String username) {
//        boolean isExist = false;
//        for (Map.Entry<UUID, User> entry : users.entrySet()) {
//            if (entry.getValue().username.equals(username)) {
//                isExist = true;
//                break;
//            }
//        }
//        return isExist;
//    }
    public synchronized boolean isUserExistAndOnline(String username) {
        boolean isExistAndOnline = false;
        for (Map.Entry<UUID, User> entry : users.entrySet()) {
            if (entry.getValue().username.equals(username)) {
                if (entry.getValue().isOnline()) {
                    isExistAndOnline = true;
                }
                break;
            }
        }
        return isExistAndOnline;
    }

    public synchronized User getUser(UUID uuid) {
        return users.get(uuid);
    }

    public synchronized User getUser(int userId) {
        User user = null;
        for (Map.Entry<UUID, User> entry : users.entrySet()) {
            if (entry.getValue().id == userId) {
                user = entry.getValue();
                break;
            }
        }
        return user;
    }

    public synchronized UUID addUser(String username) {

        UUID oldUUID = null;
        for (Map.Entry<UUID, User> entry : users.entrySet()) {
            if (entry.getValue().username.equals(username)) {
                oldUUID = entry.getKey();
                break;
            }
        }
        UUID uuid = UUID.randomUUID();
        if (oldUUID == null) {
            User user = new User(username, System.currentTimeMillis(), atomicInteger.getAndIncrement());
            users.put(uuid, user);
        } else {
            users.put(uuid, users.remove(oldUUID));
        }
        users.get(uuid).login();
        return uuid;
    }

    synchronized void checkTimeoutForUsers() {
        long curTime = System.currentTimeMillis();
        for (User user : users.values()) {
            user.checkTime(curTime);
        }
    }

    public synchronized void removeUser(UUID userUUID) {
        users.remove(userUUID);
    }

//    public void updateTime(UUID userUUID) {
//        users.get(userUUID).setLastRequestTime();
//    }

    public class User {
        private int id;
        private String username;
        private long lastRequestTime;
        private Boolean online;

        User(String username, long lastRequestTime, int id) {
            this.id = id;
            this.username = username;
            this.lastRequestTime = lastRequestTime;
        }

        public Boolean getOnlineStatus() {
            return online;
        }

        boolean isOnline() {
            return online != null && online;
        }

        public String getUsername() {
            return username;
        }

        public void logout() {
            online = false;
            MessagesController.getInstance().addMessage("User " + username + " logout", "SYSTEM_MESSAGE");
        }

        void login() {
            online = true;
            MessagesController.getInstance().addMessage("User " + username + " login", "SYSTEM_MESSAGE");
        }

        public int getId() {
            return id;
        }

        private void checkTime(long curTime) {
            if ((online != null) && online && (curTime - lastRequestTime) > 10000) {
                online = null;
                MessagesController.getInstance().addMessage("User " + username + " logout from timeout", "SYSTEM_MESSAGE");
            }
        }

        void setLastRequestTime() {
            this.lastRequestTime = System.currentTimeMillis();
        }
    }
}
