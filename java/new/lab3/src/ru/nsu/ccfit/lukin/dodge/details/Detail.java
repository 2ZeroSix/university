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
    protected double speed;
    protected double circularSpeed;
    protected boolean destroyed = false;
    protected WeakReference<Model> model;

    public Detail(Model model, Position position, double speed, double circularSpeed) throws DodgeException {
        this.model = new WeakReference<>(model);
        this.position = position != null ? position : new Position();
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
        return position.getRadius();
    }

    public void setRadius(double radius) {
        position.setRadius(radius);
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
        if (!isDestroyed()) {
            Model model = getModel();
            if (model == null) return;
            try {
                model.add(new Explosion(getModel(), position));
            } catch (DodgeException e) {
                e.printStackTrace();
            }
            destroyed = true;
            model.getView().remove(this);
        }
    }

    public boolean isDestroyed() {
        return destroyed;
    }

    public boolean isContains(Position position) {
        return Math.sqrt((this.position.getX() - position.getX())*(this.position.getX() - position.getX()) +
                (this.position.getY() - position.getY())*(this.position.getY() - position.getY()))< getRadius();
    }

    public abstract void move() throws DodgeException;

    public void update() throws DodgeException {
        Model model = getModel();
        if (model == null) return;
        View view = model.getView();
        if (view != null) view.update(this);
    }

    public void act() throws DodgeException {
        if (isDestroyed()) return;
        move();
        update();
    }
}