package ru.nsu.ccfit.lab6.client;

import java.util.LinkedList;
import java.util.Scanner;

public class ConsoleReader extends Thread {
    private LinkedList<String> strings = new LinkedList<>();

    @Override
    public void run() {
        Scanner scanner = new Scanner(System.in);
        while (!isInterrupted()) {
            String nextLine = scanner.nextLine();
            synchronized (this) {
                strings.addLast(nextLine);
                notifyAll();
            }
        }
    }

    synchronized String getNextLine() throws InterruptedException {
        while (strings.isEmpty()){
            wait();
        }
        return strings.removeFirst();
    }

    synchronized boolean hasNext() {
        return !strings.isEmpty();
    }
}
