package ru.nsu.ccfit.lukin.dodge.details;

import ru.nsu.ccfit.lukin.dodge.DodgeException;
import ru.nsu.ccfit.lukin.dodge.Model;
import ru.nsu.ccfit.lukin.dodge.View;

import java.lang.ref.WeakReference;

/**
 * Created by dzs on 04.05.17.
 */
public abstract class Detail{
    protected Position position;
    protected double radius;
    protected double speed;
    protected double circularSpeed;
    protected boolean destroyed = false;
    protected WeakReference<Model> model;

    public Detail(Model model, Position position, double radius, double speed, double circularSpeed) throws DodgeException {
        this.model = new WeakReference<>(model);
        this.position = position != null ? position : new Position();
        this.radius = radius;
        this.speed = speed;
        this.circularSpeed = circularSpeed;
        update();
    }

    public Position getPosition() {
        return position;
    }

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

    public Model getModel() {
        return model.get();
    }

    public void destroy() {
        destroyed = true;
    }

    public boolean isDestroyed() {
        return destroyed;
    }

    public boolean isContains(Position position) {
        return Math.abs(this.position.getX() - position.getX()) < radius &&
                Math.abs(this.position.getY() - position.getY()) < radius;
    }

    public abstract void move();

    public void update() throws DodgeException {
        View view = getModel().getView();
        if (view != null) view.update(this);
    }

    public void act() throws DodgeException {
        if (isDestroyed()) return;
        move();
        update();
    }
}