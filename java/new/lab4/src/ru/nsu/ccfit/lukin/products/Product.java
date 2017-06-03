package ru.nsu.ccfit.lukin.products;

/**
 * Created by dzs on 03.06.17.
 */
public abstract class Product {
    private String info;
    protected String id;
    Product(String info, String id) {
        this.info = info;
        this.id = id;
    }
    public String getId() {
        return id;
    }
    public String getInfo() {
        return info + ": " + id;
    }
}
