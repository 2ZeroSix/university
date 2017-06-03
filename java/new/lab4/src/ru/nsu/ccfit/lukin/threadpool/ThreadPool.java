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
    private AtomicBoolean runnable = new AtomicBoolean(true);
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

    private void worker() {
        while (runnable.get()) {
            try {
                synchronized (this) {
                    wait();
                }
            } catch (InterruptedException e) {
                continue;
            }
            Runnable task = tasks.poll();
            if (task != null) {
                task.run();
            }
        }
    }

    public void stop() {
        runnable.set(false);
        for (Thread thread : workers) {
            thread.interrupt();
            try {
                thread.join();
            } catch (InterruptedException ignore) {}
        }
    }
}
