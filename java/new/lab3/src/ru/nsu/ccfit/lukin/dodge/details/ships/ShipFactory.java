package ru.nsu.ccfit.lukin.dodge.details.ships;

import ru.nsu.ccfit.lukin.dodge.DodgeException;
import ru.nsu.ccfit.lukin.dodge.components.DetailViewFactory;

import javax.swing.*;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Properties;

/**
 * Created by dzs on 09.05.17.
 */
public class ShipFactory {
    private static Map<String, Class<Ship>> shipMap = new HashMap<>();

    static {
        Properties props = new Properties();
        try {
            props.load(DetailViewFactory.class.getResourceAsStream("ShipFactory.prop"));
        } catch (IOException e) {
            e.printStackTrace();
        }
        props.stringPropertyNames().forEach(str -> {
            try {
                shipMap.put(str, (Class<Ship>) Class.forName(props.getProperty(str)));
            } catch (ClassNotFoundException e) {
                e.printStackTrace();
            }
        });
    }

    public Ship get(String string) throws DodgeException {
        Ship ship = null;
        try {
            ship = shipMap.get(string).newInstance();
            if (ship == null)
                throw new DodgeException("Can't find ship for name: " + string);
        } catch (Throwable e) {
            if (e instanceof DodgeException) throw (DodgeException) e;
            throw new DodgeException("Error while searching ship for name: "
                                        + string, e);
        }
        return ship;
    }
}
