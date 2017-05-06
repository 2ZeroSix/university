package ru.ccfit.nsu.ru.lukin.dodge.details;

/**
 * Created by dzs on 03.05.17.
 */
public class ArmedShipController {
    private ArmedShip ship;
    private Ship target;
    private int stepsToFire;
    private int stepsToChangePosition;
    private int step;
    public ArmedShipController(ArmedShip ship, Ship target) {
        this(ship, target, 180, 180 * 5);
    }

    public ArmedShipController(ArmedShip ship, Ship target, int stepsToFire, int stepsToChangePosition) {
        this.ship = ship;
        this.target = target;
        this.stepsToFire = stepsToFire;
        this.stepsToChangePosition = stepsToChangePosition;
    }

    public ArmedShip getShip() {
        return ship;
    }

    public void step() {
        ship.move();
        ship.setPreferredAngle(ship.getPosition().bestAngleTo(target.getPosition()));
        ++step;
        if (step % stepsToFire == 0) {
            ship.fire();
        }
        if (step % stepsToChangePosition == 0) {
            ship.ge
        }
    }
}
