package ru.ccfit.nsu.ru.lukin.dodge.details;

/**
 * Created by dzs on 03.05.17.
 */
public class ArmedShipController {
    private ArmedShip ship;
    private Ship target;
    private int stepsToFire;
    private int step;
    public ArmedShipController(ArmedShip ship, Ship target) {
        this(ship, target, 300);
    }

    public ArmedShipController(ArmedShip ship, Ship target, int stepsToFire) {
        this.ship = ship;
        this.target = target;
        this.stepsToFire = stepsToFire;
    }
    public void step() {
        ship.move();
        if (++step % stepsToFire == 0) {
            ship.fire();
        }
    }
}
