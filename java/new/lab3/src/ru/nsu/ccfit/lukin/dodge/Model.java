package ru.nsu.ccfit.lukin.dodge;

import ru.nsu.ccfit.lukin.dodge.details.missiles.Missile;
import ru.nsu.ccfit.lukin.dodge.details.ships.ArmedShip;
import ru.nsu.ccfit.lukin.dodge.details.ships.Ship;
import ru.nsu.ccfit.lukin.dodge.details.ships.ShipFactory;

import java.util.HashSet;
import java.util.Set;

/**
 * Created by dzs on 03.05.17.
 */
public class Model {
    private int height;
    private int width;
    final private Ship player;
    final private Set<ArmedShip> enemies;
    final private Set<Missile> missiles = new HashSet<>();
    final private ShipFactory shipFactory = new ShipFactory();
    public Model(int height, int width) throws DodgeException {
        this(height, width, null);
    }

    public Model(int height, int width, Ship ship) throws DodgeException {
        this.height = height;
        this.width = width;
        enemies = new HashSet<>();
        player = ship != null ? ship : shipFactory.get("player");
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
        return player;
    }

    public Set<ArmedShip> getEnemiesShips() {
        return enemies;
    }

    public void addEnemyShip(ArmedShip asc) {
        enemies.add(asc);
    }

    public void removeEnemyShip(ArmedShip asc) {
        enemies.remove(asc);
    }

    public Set<Missile> getMissiles() {
        return missiles;
    }

    public void addMissile(Missile missile) {
        missiles.add(missile);
    }

    public void removeMissile(Missile missile) {
        missiles.remove(missile);
    }
}
