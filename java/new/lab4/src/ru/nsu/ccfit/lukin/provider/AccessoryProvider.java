package ru.nsu.ccfit.lukin.provider;

import ru.nsu.ccfit.lukin.products.Accessory;
import ru.nsu.ccfit.lukin.storage.Storage;
import ru.nsu.ccfit.lukin.threadpool.ThreadPool;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * Created by dzs on 03.06.17.
 */
public class AccessoryProvider extends Provider<Accessory> {
    private DateFormat df = new SimpleDateFormat("dd/MM/yy HH:mm:ss");
    private String nameOfAccessory;
    private int threads;

    public AccessoryProvider(Storage<Accessory> stock, long delay, String nameOfAccessory, int threads) {
        super(stock, delay);
        this.nameOfAccessory = nameOfAccessory;
        this.threads = threads;
    }

    public AccessoryProvider(Storage<Accessory> stock, long delay, int threads) {
        this(stock, delay, "", threads);
    }

    public void run() {
        ThreadPool threadPool = new ThreadPool(threads);
        for (int i = 0; i < threads - 1; ++i) {
            threadPool.addTask(super::run);
        }
        super.run();
        threadPool.stop();
    }
    @Override
    protected Accessory createProduct() {
        return new Accessory((nameOfAccessory.equals("") ? "" : nameOfAccessory) + df.format(new Date()));
    }
}
