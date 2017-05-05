package ru.ccfit.nsu.ru.lukin.dodge.details;

import ru.ccfit.nsu.ru.lukin.dodge.Model;

/**
 * Created by dzs on 03.05.17.
 */
public class Ship extends RoundDetail {
    protected double preferredAngle = Math.PI/2;
    protected double health;
    public Ship(Model model) {
        this(model, null);
    }

    public Ship(Model model, Position position) {
        this(model, position, 10.);
    }

    public Ship(Model model, Position position, double radius) {
        this(model, position, radius, Math.PI / 2);
    }

    public Ship(Model model, Position position, double radius, double angle) {
        this(model, position, radius, angle, radius);
    }

    public Ship(Model model, Position position, double radius, double angle, double speed) {
        this(model, position, radius, angle, speed, 2*Math.PI);
    }

    public Ship(Model model, Position position, double radius, double angle, double speed, double circularSpeed){
        this(model, position, radius, angle, speed, circularSpeed, 100.);
    }

    public Ship(Model model, Position position, double radius, double angle, double speed, double circularSpeed, double health){
        super(model, position, radius, angle, speed, circularSpeed);
        this.health = health;
    }

    public void setHealth(double health) {
        this.health = health;
    }

    public double getHealth() {
        return health;
    }

    public void makeDamage(double damage) {
        health -= damage;
        if (health <= 0) destroyed = true;
    }

    public void move() {
        if (destroyed) return;
        setPosition(new Position(position.x + speed * Math.cos(angle), position.y + speed * Math.sin(angle)));
        angle = circularSpeed >= Math.abs(preferredAngle - angle)
                ? preferredAngle
                : angle + circularSpeed * Math.signum(angle - preferredAngle);
    }
}
