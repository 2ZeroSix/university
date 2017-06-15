package ru.nsu.ccfit.lukin.dodge;

import ru.nsu.ccfit.lukin.dodge.details.Detail;
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
    final private Ship player;
    final private Set<ArmedShip> enemies = new HashSet<>();
    final private Set<Missile> missiles = new HashSet<>();
    final private Set<Detail> details = new HashSet<>();
    private View view;



    public Model() throws DodgeException {
        this(null);
    }

    public Model(Ship ship) throws DodgeException {
        player = ship != null ? ship : new ShipFactory(this).get("player");
    }


    public Ship getPlayerShip() {
        return player;
    }

    public Set<ArmedShip> getEnemiesShips() {
        return enemies;
    }

    public void add(Detail detail) {
        if (detail instanceof ArmedShip)    enemies.add((ArmedShip)detail);
        else if (detail instanceof Missile) missiles.add((Missile)detail);
        else                                details.add(detail);
    }

    public void remove(Detail detail) {
        if (detail instanceof ArmedShip)    enemies.remove((ArmedShip)detail);
        else if (detail instanceof Missile) missiles.remove((Missile)detail);
        else                                details.remove(detail);
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

    public void setView(View view) {
        this.view = view;
        try {
            player.update();
            for (ArmedShip enemy : enemies) {
                enemy.update();
            }
            for (Missile missile : missiles) {
                missile.update();
            }
            for (Detail detail : details) {
                detail.update();
            }
        } catch (DodgeException e) {
            e.printStackTrace();
        }

    }

    public View getView() {
        return view;
    }

    public Set<Detail> getDetails() {
        return details;
    }

}
