package ru.nsu.ccfit.lukin.dodge.details.ships;

import ru.nsu.ccfit.lukin.dodge.Model;
import ru.nsu.ccfit.lukin.dodge.details.Position;
import ru.nsu.ccfit.lukin.dodge.details.RoundDetail;

/**
 * Created by dzs on 03.05.17.
 */
public class Ship extends RoundDetail {
    protected double preferredAngle = Math.PI/2;
    protected int health;
    public Ship(Model model) {
        this(model, null);
    }

    public Ship(Model model, Position position) {
        this(model, position, 10.);
    }

    public Ship(Model model, Position position, double radius) {
        this(model, position, radius, radius);
    }

    public Ship(Model model, Position position, double radius, double speed) {
        this(model, position, radius, speed, 2*Math.PI);
    }

    public Ship(Model model, Position position, double radius, double speed, double circularSpeed){
        this(model, position, radius, speed, circularSpeed, 1000);
    }

    public Ship(Model model, Position position, double radius, double speed, double circularSpeed, int health){
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

    public void harm(double damage) {
        health -= Math.max(damage, 0);
        if (health <= 0) destroyed = true;
    }

    public void move() {
        if (destroyed) return;
        setPosition(new Position(position.getX() + speed * Math.cos(position.getAngle()),
                                    position.getY() + speed * Math.sin(position.getAngle())));
        position.setAngle(circularSpeed >= Math.abs(preferredAngle - position.getAngle())
                ? preferredAngle
                : position.getAngle() + circularSpeed * Math.signum(position.getAngle() - preferredAngle));
    }
}
