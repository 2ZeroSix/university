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


    public ArmedShip(Model model) throws DodgeException {
        super(model);
    }

    public ArmedShip(Model model, Position position, double speed,
                     double circularSpeed, int health, Class<Missile> missileClass) throws DodgeException {
        super(model, position, speed, circularSpeed, health);
        this.missileClass = missileClass;
    }
    public Class<? extends Missile> getMissileClass() {
        return missileClass;
    }

    public ArmedShip setMissileClass(Class<? extends Missile> missileClass) {
        this.missileClass = missileClass;
        return this;
    }

    public void fire() throws DodgeException {
        Model model = this.model.get();
        if (model == null) return;
        try {
            Position missilePosition = new Position(Math.min(1, Math.max(0, position.getX() - (getRadius() + 1E-5) * Math.cos(position.getAngle()))),
                    Math.min(1, Math.max(0, position.getY() + (getRadius() + 1E-5) * Math.sin(position.getAngle()))),
                    position.getAngle());
            model.add(this.missileClass.getConstructor(Model.class, Position.class).newInstance(model, missilePosition));
        } catch (Exception e) {
            throw new DodgeException("Can't create missile: " + missileClass.getName(), e);
        }
    }
}
