package ru.nsu.ccfit.lukin.products;

/**
 * Created by dzs on 03.06.17.
 */
public class Auto extends Product {
    private Body body;
    private Motor engine;
    private Accessory accessory;

    public Auto(String id, Body body, Motor engine, Accessory accessory) {
        super("Auto", id);
        this.body = body;
        this.engine = engine;
        this.accessory = accessory;
    }

    @Override
    public String getInfo() {
        return super.getInfo() + " (" + body.getInfo() + ", " +
                engine.getInfo() + ", " + accessory.getInfo() + ")";
    }
}
