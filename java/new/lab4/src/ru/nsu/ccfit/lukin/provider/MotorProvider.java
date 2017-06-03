package ru.nsu.ccfit.lukin.provider;

import ru.nsu.ccfit.lukin.products.Motor;
import ru.nsu.ccfit.lukin.storage.Storage;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * Created by dzs on 03.06.17.
 */
public class MotorProvider extends Provider<Motor> {
    private DateFormat df = new SimpleDateFormat("dd/MM/yy HH:mm:ss");
    public MotorProvider(Storage<Motor> stock, long delay) {
        super(stock, delay);
    }

    @Override
    protected Motor createProduct() {
        return new Motor(df.format(new Date()));
    }
}
