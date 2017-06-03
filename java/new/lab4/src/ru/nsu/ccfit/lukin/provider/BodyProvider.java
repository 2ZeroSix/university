package ru.nsu.ccfit.lukin.provider;

import ru.nsu.ccfit.lukin.products.Body;
import ru.nsu.ccfit.lukin.storage.Storage;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * Created by dzs on 03.06.17.
 */
public class BodyProvider extends Provider<Body> {
    private DateFormat df = new SimpleDateFormat("dd/MM/yy HH:mm:ss");
    public BodyProvider(Storage<Body> stock, long delay) {
        super(stock, delay);
    }

    @Override
    protected Body createProduct() {
        return new Body(df.format(new Date()));
    }
}
