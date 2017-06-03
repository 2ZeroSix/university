package ru.nsu.ccfit.lukin.dealer;

import ru.nsu.ccfit.lukin.products.Auto;
import ru.nsu.ccfit.lukin.storage.Storage;

import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicLong;

/**
 * Created by dzs on 03.06.17.
 */
public class Dealer implements Runnable{
    private Storage<Auto> autoStorage;

    private AtomicLong delay;
    private AtomicBoolean runnable = new AtomicBoolean(true);

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
        while(runnable.get()) {
            try {
                Thread.sleep(delay.get());
                autoStorage.poll();
            } catch (InterruptedException ignored) {}
        }
    }

    public void stop() {
        runnable.set(false);
    }
}
