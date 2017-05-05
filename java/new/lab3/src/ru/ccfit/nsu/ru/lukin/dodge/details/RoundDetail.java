package ru.ccfit.nsu.ru.lukin.dodge.details;

import ru.ccfit.nsu.ru.lukin.dodge.Model;

import java.lang.ref.WeakReference;

/**
 * Created by dzs on 04.05.17.
 */
public abstract class RoundDetail implements Detail {
    protected Position position;
    protected double radius;
    protected double angle;
    protected double speed;
    protected double circularSpeed;
    protected boolean destroyed = false;
    protected WeakReference<Model> model;
    public RoundDetail(Model model, Position position, double radius, double angle, double speed, double circularSpeed) {
        this.position = position != null ? position : new Position();
        this.radius = radius;
        this.speed = speed;
        this.circularSpeed = circularSpeed;
        this.angle = angle;
    }

    @Override
    public Position getPosition() {
        return position;
    }

    @Override
    public void setPosition(Position position) {
        Model model = this.model.get();
        this.position = position;
        if (position.x > model.getWidth()/2) {
            position.x = model.getWidth()/2;
        }
        if (position.x < -model.getWidth()/2) {
            position.x = -model.getWidth()/2;
        }
        if (position.y > model.getHeight()/2)
            position.y = model.getHeight()/2;
        if (position.y > -model.getHeight()/2)
            position.y = -model.getHeight()/2;

    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public double getAngle() {
        return angle;
    }

    public void setAngle(double angle) {
        this.angle = angle;
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
    public boolean isInside(double x, double y) {
        return Math.abs(position.getX() - x) < radius &&
                Math.abs(position.getY() - y) < radius;
    }
}
