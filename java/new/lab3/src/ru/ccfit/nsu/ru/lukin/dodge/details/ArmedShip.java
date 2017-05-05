package ru.ccfit.nsu.ru.lukin.dodge.details;

import ru.ccfit.nsu.ru.lukin.dodge.Model;

/**
 * Created by dzs on 04.05.17.
 */
public class ArmedShip extends Ship implements Armed{
    private double damage;

    public ArmedShip(Model model) {
        super(model);
    }

    public ArmedShip(Model model, Position position) {
        super(model, position);
    }

    public ArmedShip(Model model, Position position, double radius) {
        super(model, position, radius);
    }

    public ArmedShip(Model model, Position position, double radius, double angle) {
        super(model, position, radius, angle);
    }

    public ArmedShip(Model model, Position position, double radius, double angle, double speed) {
        super(model, position, radius, angle, speed);
    }

    public ArmedShip(Model model, Position position, double radius, double angle, double speed,
                     double circularSpeed) {
        super(model, position, radius, angle, speed, circularSpeed);
        this.damage = health / 4;
    }

    public ArmedShip(Model model, Position position, double radius, double angle, double speed,
                     double circularSpeed, double health) {
        this(model, position, radius, angle, speed, circularSpeed, health, health/4.);
    }

    public ArmedShip(Model model, Position position, double radius, double angle, double speed,
                     double circularSpeed, double health, double damage) {
        super(model, position, radius, angle, speed, circularSpeed, health);
        this.damage = damage;
    }

    public double getDamage() {
        return damage;
    }

    public void setDamage(double damage) {
        this.damage = damage;
    }

    public void fire() {

    }
}
