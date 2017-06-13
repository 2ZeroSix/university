package ru.nsu.ccfit.lukin.threadpool;

import java.util.Queue;
import java.util.concurrent.ConcurrentLinkedDeque;
import java.util.concurrent.SynchronousQueue;
import java.util.concurrent.atomic.AtomicBoolean;

/**
 * Created by dzs on 03.06.17.
 */
public class ThreadPool {
    private Queue<Runnable> tasks = new ConcurrentLinkedDeque<>();
    private Thread[] workers;
    public ThreadPool(int threads) {
        workers = new Thread[threads];
        for (int i = 0; i < threads; ++i) {
            workers[i] = new Thread(this::worker);
            workers[i].start();
        }
    }

    public void addTask(Runnable task) {
        tasks.add(task);
        synchronized (this) {
            notifyAll();
        }
    }

    public void addTaskBlocking(Runnable task) {
        synchronized (this) {
            while (!Thread.currentThread().isInterrupted()) {
                if (tasks.isEmpty()) {
                    addTask(task);
                    return;
                } else {
                    try {
                        wait();
                    } catch (InterruptedException e) {
                        Thread.currentThread().interrupt();
                    }
                }
            }
        }
    }

    private void worker() {
        while (!Thread.currentThread().isInterrupted()) {
            Runnable task;
            synchronized (this) {
                task = tasks.poll();
                if (task == null) {
                    try {
                        wait();
                    } catch (InterruptedException e) {
                        break;
                    }
                    continue;
                }
                notifyAll();
            }
            task.run();
        }
    }

    public void stop() {
        for (Thread thread : workers) {
            thread.interrupt();
            try {
                thread.join();
            } catch (InterruptedException ignore) {}
        }
    }
}
