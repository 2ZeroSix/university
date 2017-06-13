package ru.nsu.ccfit.lukin.dealer;

import ru.nsu.ccfit.lukin.products.Auto;
import ru.nsu.ccfit.lukin.storage.Storage;

import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicLong;

/**
 * Created by dzs on 03.06.17.
 */
public class Dealer implements Runnable {
    private Storage<Auto> autoStorage;

    private AtomicLong delay;

    public Dealer(Storage<Auto> autoStorage, long delay) {
        this.autoStorage = autoStorage;
        this.delay = new AtomicLong(delay);
    }

    public long getDelay() {
        return delay.get();
    }

    public Dealer setDelay(long delay) {
        this.delay.set(delay);
        return this;
    }

    @Override
    public void run() {
        while(!Thread.currentThread().isInterrupted()) {
            try {
                Thread.sleep(delay.get());
                autoStorage.poll();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }

}
