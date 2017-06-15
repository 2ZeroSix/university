package ru.nsu.ccfit.lukin.dodge.details.ships;

import ru.nsu.ccfit.lukin.dodge.DodgeException;
import ru.nsu.ccfit.lukin.dodge.Model;
import ru.nsu.ccfit.lukin.dodge.details.Position;

/**
 * Created by dzs on 10.05.17.
 */
public class EnemyShip extends ArmedShip {
    private int stepsToFire = 0;
    private int stepToChangeTarget = 0;
    private int stepToFire = 0;

    public int getStepsToChangeTarget() {
        return stepsToChangeTarget;
    }

    public void setStepsToChangeTarget(int stepsToChangeTarget) {
        this.stepsToChangeTarget = stepsToChangeTarget;
    }

    private int stepsToChangeTarget = 0;
    private Position target = new Position(Math.random(), Math.random());
    public EnemyShip(Model model) throws DodgeException {
        super(model);
    }

    public int getStepsToFire() {
        return stepsToFire;
    }

    public void setStepsToFire(int stepsToFire) {
        this.stepsToFire = stepsToFire;
    }

    public void move() throws DodgeException {
        if (!position.equals(target)) {
            preferredAngle = position.angleTo(target);
            try {
                setPosition(position.nearestAfterMove(target, speed, circularSpeed));
            } catch (Position.PositionException ignore) {
            }
        } else {
            if (stepToChangeTarget % stepsToChangeTarget == 0) {
                target.setX(Math.random());
                target.setY(Math.random());
                stepToChangeTarget++;
            }
            preferredAngle = position.angleTo(getModel().getPlayerShip().getPosition());
            position.setAngle(preferredAngle);
            stepToChangeTarget++;
            stepToFire++;
            if (stepToFire % stepsToFire == 0) {
                fire();
            }
        }
    }
}
