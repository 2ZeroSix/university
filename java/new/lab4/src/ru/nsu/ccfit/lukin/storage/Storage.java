package ru.nsu.ccfit.lukin.storage;

import ru.nsu.ccfit.lukin.products.Product;

import java.util.Queue;
import java.util.concurrent.ConcurrentLinkedQueue;
import java.util.concurrent.SynchronousQueue;
import java.util.concurrent.atomic.AtomicLong;

/**
 * Created by dzs on 03.06.17.
 */
public class Storage<P extends Product> {
    private final Queue<P> queue = new ConcurrentLinkedQueue<>();
    private long capacity;

    public long getProducts() {
        return products.get();
    }

    private AtomicLong products = new AtomicLong(0);
    public Storage(long capacity) {
        this.capacity = capacity;
    }
    public void put(P product) throws InterruptedException {
        synchronized (this) {
            while (true) {
                    if (capacity > products.get()) {
                        queue.add(product);
                        products.incrementAndGet();
                        notifyAll();
                        break;
                    }
                wait();
            }
        }
    }

    public P poll() throws InterruptedException {
        P product;
        product = queue.poll();
        if (product != null) {
            synchronized (this) {
                    products.decrementAndGet();
                notifyAll();
            }
        }
        return product;
    }
}
