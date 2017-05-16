package ru.nsu.ccfit.lukin.dodge.details.ships;

import ru.nsu.ccfit.lukin.dodge.DodgeException;
import ru.nsu.ccfit.lukin.dodge.Model;
import ru.nsu.ccfit.lukin.dodge.details.Position;

/**
 * Created by dzs on 10.05.17.
 */
public class EnemyShip extends ArmedShip {
    private int stepsToFire = 0;

    public int getStepsToChangeTarget() {
        return stepsToChangeTarget;
    }

    public void setStepsToChangeTarget(int stepsToChangeTarget) {
        this.stepsToChangeTarget = stepsToChangeTarget;
    }

    private int stepsToChangeTarget = 0;
    private int steps = 0;
    Position target = new Position();
    public EnemyShip(Model model) throws DodgeException {
        super(model);
    }

    public int getStepsToFire() {
        return stepsToFire;
    }

    public void setStepsToFire(int stepsToFire) {
        this.stepsToFire = stepsToFire;
    }

    public void act() throws DodgeException {
        if (step++ % stepsToChangeTarget == 0) {
            target.setX(Math.random());
            target.setY(Math.random());
        }
        super.act();
        if (step % stepsToFire == 0) {
            fire();
        }
    }

    public void move() {
        if (!position.equals(target)) {
            preferredAngle = position.angleTo(target);
            try {
                setPosition(new Position(position.getX() + speed * Math.cos(position.getAngle()),
                        position.getY() + speed * Math.sin(position.getAngle())));
            } catch (Position.PositionException ignore) {
            }
        } else {
            preferredAngle = position.angleTo(getModel().getPlayerShip().getPosition());
        }
        position.setAngle(circularSpeed >= Math.abs(preferredAngle - position.getAngle())
                ? preferredAngle
                : position.getAngle() + circularSpeed * Math.signum(position.getAngle() - preferredAngle));
    }
}
