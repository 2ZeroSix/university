package ru.nsu.ccfit.lukin.storage;

import ru.nsu.ccfit.lukin.products.Product;

import java.util.Queue;
import java.util.concurrent.ConcurrentLinkedQueue;
import java.util.concurrent.SynchronousQueue;

/**
 * Created by dzs on 03.06.17.
 */
public class Storage<P extends Product> {
    private final Queue<P> queue = new ConcurrentLinkedQueue<>();
    private long capacity;
    private long products = 0;
    public Storage(long capacity) {
        this.capacity = capacity;
    }
    public void put(P product) throws InterruptedException {
        synchronized (queue) {
            while (true) {
                synchronized (this) {
                    if (capacity > products) {
                        queue.add(product);
                        ++products;
                        notifyAll();
                        break;
                    }
                }
                queue.wait();
            }
        }
    }

    public P poll() throws InterruptedException {
        P product;
        product = queue.poll();
        if (product != null) {
            synchronized (queue) {
                synchronized (this) {
                    --products;
                }
                queue.notify();
            }
        }
        return product;
    }
}
