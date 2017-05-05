package ru.ccfit.nsu.ru.lukin.dodge;

import ru.ccfit.nsu.ru.lukin.dodge.details.ArmedShipController;
import ru.ccfit.nsu.ru.lukin.dodge.details.Ship;

import java.util.HashSet;
import java.util.Set;

/**
 * Created by dzs on 03.05.17.
 */
public class Model {
    private int height;
    private int width;
    private Ship playerShip;
    private Set<ArmedShipController> enemiesShips;
    public Model(int height, int width, Ship ship) {
        this.height = height;
        this.width = width;
        enemiesShips = new HashSet<>();
        playerShip = new Ship(this,null, Math.min(height, width) / 50.);
    }

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public int getWidth() {
        return width;
    }

    public void setWidth(int width) {
        this.width = width;
    }

    public Ship getPlayerShip() {
        return playerShip;
    }

    public void setPlayerShip(Ship playerShip) {
        this.playerShip = playerShip;
    }

    public Set<ArmedShipController> getEnemiesShips() {
        return enemiesShips;
    }

    public void addEnemyShip(ArmedShipController asc) {
        enemiesShips.add(asc);
    }

    public void removeEnemyShip(ArmedShipController asc) {
        enemiesShips.remove(asc);
    }
}
