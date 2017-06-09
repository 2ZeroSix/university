package ru.nsu.ccfit.lukin.provider;

import ru.nsu.ccfit.lukin.products.Product;
import ru.nsu.ccfit.lukin.storage.Storage;

import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicLong;

/**
 * Created by dzs on 03.06.17.
 */
public abstract class Provider<P extends Product> implements Runnable {
    private AtomicLong delay;
    private Storage<P> stock;
    private AtomicLong total = new AtomicLong(0);
    private AtomicBoolean runnable = new AtomicBoolean(true);
    public Provider(Storage<P> stock, long delay) {
        this.stock = stock;
        this.delay = new AtomicLong(delay);
    }

    public void run() {
        while (runnable.get()) {
            try {
                Thread.sleep(delay.get());
                stock.put(createProduct());
                total.addAndGet(1);
            } catch (InterruptedException ignored) {}
        }
    }

    abstract protected P createProduct();

    public long getDelay() {
        return delay.get();
    }

    public Provider setDelay(long delay) {
        this.delay.set(delay);
        return this;
    }

    public void stop() {
        runnable.set(false);
    }

    public long getTotal() {
        return total.get();
    }
}
