package ru.nsu.ccfit.lukin.factory;

import ru.nsu.ccfit.lukin.products.Accessory;
import ru.nsu.ccfit.lukin.products.Auto;
import ru.nsu.ccfit.lukin.products.Body;
import ru.nsu.ccfit.lukin.products.Motor;
import ru.nsu.ccfit.lukin.storage.AutoStorage;
import ru.nsu.ccfit.lukin.storage.Storage;
import ru.nsu.ccfit.lukin.threadpool.ThreadPool;

import java.io.IOException;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Properties;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicLong;

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
    private static final int workers;
    private static final boolean log;
    private AtomicBoolean runnable = new AtomicBoolean(true);
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

    @Override
    public void run() {
        while (runnable.get()) {
            Body body = null;
            Motor motor = null;
            Accessory accessory = null;
            while (runnable.get()) {
                try {
                    body = bodyStorage.poll();
                } catch (InterruptedException e) {
                    continue;
                }
                if (body != null) {
                    break;
                }
            }
            while (runnable.get()) {
                try {
                    motor = motorStorage.poll();
                } catch (InterruptedException e) {
                    continue;
                }
                if (motor != null) {
                    break;
                }
            }
            while (runnable.get()) {
                try {
                    accessory = accessoryStorage.poll();
                } catch (InterruptedException e) {
                    continue;
                }
                if (accessory != null) {
                    break;
                }
            }
            if (runnable.get()) {
                Body finalBody = body;
                Motor finalMotor = motor;
                Accessory finalAccessory = accessory;
                threadPool.addTask(() -> {
                    try {
                        autoStorage.put(new Auto(df.format(new Date()), finalBody, finalMotor, finalAccessory));
                        Thread.sleep(delay.get());
                    } catch (InterruptedException ignored) {
                    }
                });
            }
        }
    }

    public long getDelay() {
        return delay.get();
    }

    public AutoFactory setDelay(long delay) {
        this.delay.set(delay);
        return this;
    }

    public void stop() {
        threadPool.stop();
        runnable.set(false);
    }
}
