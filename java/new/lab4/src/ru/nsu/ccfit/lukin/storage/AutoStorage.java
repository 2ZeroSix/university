package ru.nsu.ccfit.lukin.storage;

import ru.nsu.ccfit.lukin.products.Auto;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * Created by dzs on 03.06.17.
 */
public class AutoStorage extends Storage<Auto> {
    private DateFormat df = new SimpleDateFormat("dd/MM/yy HH:mm:ss");

    public boolean isLog() {
        return log;
    }

    public AutoStorage setLog(boolean log) {
        this.log = log;
        return this;
    }

    private boolean log = false;

    public AutoStorage(long capacity) {
        super(capacity);
        this.log = log;
    }

    @Override
    public Auto poll() throws InterruptedException {
        Auto auto = super.poll();
        if (auto != null && log)
            System.out.println(df.format(new Date()) + " Dealer: " +
                    Thread.currentThread().getId() + " " + auto.getInfo());
        return auto;
    }
}
