package ru.nsu.ccfit.lukin.factory;

import ru.nsu.ccfit.lukin.products.*;
import ru.nsu.ccfit.lukin.storage.AutoStorage;
import ru.nsu.ccfit.lukin.storage.Storage;
import ru.nsu.ccfit.lukin.threadpool.ThreadPool;

import java.io.IOException;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Properties;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicLong;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 * Created by dzs on 03.06.17.
 */
public class AutoFactory implements Runnable {
    private final ThreadPool threadPool;
    private AutoStorage autoStorage;
    private final Storage<Body> bodyStorage;
    private final Storage<Motor> motorStorage;
    private final Storage<Accessory> accessoryStorage;
    private AtomicLong delay;

    public AtomicLong getProduced() {
        return produced;
    }

    private AtomicLong produced = new AtomicLong(0);
    private static final int workers;
    private static final boolean log;
    private DateFormat df = new SimpleDateFormat("dd/MM/yy HH:mm:ss");

    static {
        Properties props = new Properties();
        try {
            props.load(AutoFactory.class.getResourceAsStream("/ru/nsu/ccfit/lukin/production.prop"));
        } catch (IOException e) {
            e.printStackTrace();
        }
        workers = Integer.parseInt(props.getProperty("Workers"));
        log = Boolean.parseBoolean(props.getProperty("LogSale"));
    }

    public AutoFactory(AutoStorage autoStorage, Storage<Body> bodyStorage, Storage<Motor> motorStorage,
                       Storage<Accessory> accessoryStorage, long delay) {
        this.autoStorage = autoStorage;
        autoStorage.setLog(log);
        this.bodyStorage = bodyStorage;
        this.motorStorage = motorStorage;
        this.accessoryStorage = accessoryStorage;
        this.delay = new AtomicLong(delay);
        this.threadPool = new ThreadPool(workers);
    }

    private <P extends Product> P getProduct(Storage<P> storage) {
        synchronized (storage) {
            P product;
            while (!Thread.currentThread().isInterrupted()) {
                try {
                    product = storage.poll();
                    if (product != null) {
                        return product;
                    } else {
                        storage.wait();
                    }
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }
            }
            return null;
        }
    }

    @Override
    public void run() {
        while (!Thread.currentThread().isInterrupted()) {
            Body body = getProduct(bodyStorage);
            Motor motor = getProduct(motorStorage);
            Accessory accessory = getProduct(accessoryStorage);
            if (!Thread.currentThread().isInterrupted()) {
                threadPool.addTaskBlocking(() -> {
                    try {
                        Thread.sleep(delay.get());
                        autoStorage.put(new Auto(df.format(new Date()), body, motor, accessory));
                        produced.addAndGet(1);
                    } catch (InterruptedException e) {
                        Thread.currentThread().interrupt();
                    }
                });
            }
        }
        threadPool.stop();
    }

    public long getDelay() {
        return delay.get();
    }

    public AutoFactory setDelay(long delay) {
        this.delay.set(delay);
        return this;
    }
}
