package ru.ccfit.nsu.ru.lukin.dodge.details;

/**
 * Created by dzs on 04.05.17.
 */
public interface Detail {
    Position getPosition();
    void setPosition(Position position);
    void destroy();
    boolean isDestroyed();
    boolean isContains(Position position);
    void move();
}
