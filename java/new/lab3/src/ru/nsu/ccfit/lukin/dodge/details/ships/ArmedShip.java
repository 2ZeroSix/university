package ru.nsu.ccfit.lukin.dodge.details.ships;

import ru.nsu.ccfit.lukin.dodge.DodgeException;
import ru.nsu.ccfit.lukin.dodge.Model;
import ru.nsu.ccfit.lukin.dodge.details.missiles.Missile;
import ru.nsu.ccfit.lukin.dodge.details.Position;

/**
 * Created by dzs on 04.05.17.
 */
public class ArmedShip extends Ship implements Armed{
    private Class<? extends Missile> missileClass = null;

    protected int step = 0;

    public ArmedShip(Model model) throws DodgeException {
        super(model);
    }

    public ArmedShip(Model model, Position position, double radius, double speed,
                     double circularSpeed, int health, Class<Missile> missileClass) throws DodgeException {
        super(model, position, radius,  speed, circularSpeed, health);
        this.missileClass = missileClass;
    }
    public Class<? extends Missile> getMissileClass() {
        return missileClass;
    }

    public ArmedShip setMissileClass(Class<? extends Missile> missileClass) {
        this.missileClass = missileClass;
        return this;
    }

    public int getStep() {
        return step;
    }

    public void fire() throws DodgeException {
        Model model = this.model.get();
        try {
            Position missilePosition = new Position(position.getX() + radius * Math.cos(position.getAngle()),
                                                    position.getY() + radius * Math.sin(position.getAngle()),
                                                    position.getAngle());
            model.addMissile(this.missileClass.getConstructor(Model.class, Position.class).newInstance(model, missilePosition));
        } catch (Exception e) {
            throw new DodgeException("Can't create missile: " + missileClass.getName(), e);
        }
    }
}
