package ru.nsu.ccfit.lukin.dodge.details.ships;

import ru.nsu.ccfit.lukin.dodge.DodgeException;
import ru.nsu.ccfit.lukin.dodge.Model;
import ru.nsu.ccfit.lukin.dodge.details.Explosion;
import ru.nsu.ccfit.lukin.dodge.details.Position;
import ru.nsu.ccfit.lukin.dodge.details.Detail;

/**
 * Created by dzs on 03.05.17.
 */
public class Ship extends Detail {
    protected double preferredAngle = Math.PI/2;
    protected int health;
    public Ship(Model model) throws DodgeException {
        this(model, null);
    }

    public Ship(Model model, Position position) throws DodgeException {
        this(model, position, .01);
    }

    public Ship(Model model, Position position, double radius) throws DodgeException {
        this(model, position, radius, radius / 2);
    }

    public Ship(Model model, Position position, double radius, double speed) throws DodgeException {
        this(model, position, radius, speed, 2*Math.PI);
    }

    public Ship(Model model, Position position, double radius, double speed, double circularSpeed) throws DodgeException {
        this(model, position, radius, speed, circularSpeed, 1000);
    }

    public Ship(Model model, Position position, double radius, double speed, double circularSpeed, int health) throws DodgeException {
        super(model, position, radius, speed, circularSpeed);
        this.health = health;
    }

    public double getPreferredAngle() {
        return preferredAngle;
    }

    public void setPreferredAngle(double preferredAngle) {
        this.preferredAngle = preferredAngle;
    }

    public int getHealth() {
        return health;
    }

    public void setHealth(int health) {
        this.health = health;
    }

    public void destroy() {
        super.destroy();
    }

    public void harm(double damage) {
        health -= Math.max(damage, 0);
        if (health <= 0) destroy();
    }

    public void move() {
        try {
            setPosition(new Position(position.getX() + speed * Math.cos(position.getAngle()),
                                        position.getY() + speed * Math.sin(position.getAngle())));
        } catch (Position.PositionException ignore) {
        }
        position.setAngle(circularSpeed >= Math.abs(preferredAngle - position.getAngle())
                ? preferredAngle
                : position.getAngle() + circularSpeed * Math.signum(position.getAngle() - preferredAngle));
    }
}
