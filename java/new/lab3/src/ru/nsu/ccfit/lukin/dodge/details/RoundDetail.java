package ru.nsu.ccfit.lukin.dodge.details;

import ru.nsu.ccfit.lukin.dodge.Model;

import java.lang.ref.WeakReference;

/**
 * Created by dzs on 04.05.17.
 */
public abstract class RoundDetail implements Detail {
    protected Position position;
    protected double radius;
    protected double speed;
    protected double circularSpeed;
    protected boolean destroyed = false;
    protected WeakReference<Model> model;
    public RoundDetail(Model model, Position position, double radius, double speed, double circularSpeed) {
        this.position = position != null ? position : new Position();
        this.radius = radius;
        this.speed = speed;
        this.circularSpeed = circularSpeed;
    }

    @Override
    public Position getPosition() {
        return position;
    }

    @Override
    public void setPosition(Position position) {
        this.position = position;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public double getSpeed() {
        return speed;
    }

    public void setSpeed(double speed) {
        this.speed = speed;
    }

    public double getCircularSpeed() {
        return circularSpeed;
    }

    public void setCircularSpeed(double circularSpeed) {
        this.circularSpeed = circularSpeed;
    }

    @Override
    public void destroy() {
        destroyed = true;
    }

    public boolean isDestroyed() {
        return destroyed;
    }
    @Override
    public boolean isContains(Position position) {
        return Math.abs(this.position.x - position.x) < radius &&
                Math.abs(this.position.x - position.x) < radius;
    }
}
