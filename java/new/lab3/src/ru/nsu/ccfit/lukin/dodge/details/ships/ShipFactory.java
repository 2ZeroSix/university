package ru.nsu.ccfit.lukin.dodge.details.ships;

import ru.nsu.ccfit.lukin.dodge.DodgeException;
import ru.nsu.ccfit.lukin.dodge.Model;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Properties;
import java.util.Random;

/**
 * Created by dzs on 09.05.17.
 */
public class ShipFactory {
    private static Map<String, Class<? extends Ship>> shipMap = new HashMap<>();
    private static Map<String, Class<? extends EnemyShip>> enemyShipMap = new HashMap<>();
    private static Map<String, Map<String, ? extends Class<? extends Ship>>> mapMap = new HashMap<>();
    private Model model;
    private Random random = new Random();
    static {
        Properties props = new Properties();
        try {
            props.load(ShipFactory.class.getResourceAsStream("ShipFactory.prop"));
        } catch (IOException e) {
            e.printStackTrace();
        }
        props.stringPropertyNames().forEach(str -> {
            try {
                Class aClass = Class
                        .forName(props.getProperty(str));
                if (Ship.class.isAssignableFrom(aClass)) {
                    if (EnemyShip.class.isAssignableFrom(aClass)) {
                        mapMap.put(str, enemyShipMap);
                        enemyShipMap.put(str, aClass);
                    } else {
                        mapMap.put(str, shipMap);
                        shipMap.put(str, aClass);
                    }
                } else {
                    throw new DodgeException("Class \"" + aClass.getName() + "\" does not extend class Ship");
                }
            } catch (Throwable e) {
                e.printStackTrace();
            }
        });
    }

    public ShipFactory(Model model) {
        this.model = model;
    }

    public Ship get(String string) throws DodgeException {
        Ship ship;
        try {
            ship = shipMap.get(string).getConstructor(Model.class).newInstance(model);
        } catch (Throwable e) {
            throw new DodgeException("Error while searching for ship with name: \"" + string + "\"", e);
        }
        return ship;
    }

    public EnemyShip getEnemy() throws DodgeException {
        try {
            EnemyShip ship;
            ship = enemyShipMap
                    .values()
                    .stream()
                    .skip(random.nextInt(enemyShipMap.size()))
                    .findFirst()
                    .get()
                    .getConstructor(Model.class)
                    .newInstance(model);
            return ship;
        } catch (Throwable e) {
            throw new DodgeException("Error while searching for random enemy ship", e);
        }
    }
}
