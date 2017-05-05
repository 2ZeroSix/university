package ru.ccfit.nsu.ru.lukin.dodge.details;

/**
 * Created by dzs on 04.05.17.
 */
public interface Detail {
    Position getPosition();
    void setPosition(Position position);
    void destroy();
    boolean isDestroyed();
    boolean isInside(double x, double y);
    void move();
}
