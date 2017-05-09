package ru.ccfit.nsu.ru.lukin.dodge.details;

/**
 * Created by dzs on 03.05.17.
 */
public class Position implements Cloneable, Comparable<Position> {
    double x;
    double y;
    double angle;

    public Position() {
        this(0, 0);
    }

    public Position(double x, double y) {
        this(x, y, Math.PI / 2.);
    }

    public Position(double x, double y, double angle) {
        this.x = x;
        this.y = y;
        this.angle = angle;
    }

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }

    public void add(Position p) {
        x += p.x;
        y += p.y;
    }

    public void sub(Position p) {
        x -= p.x;
        y -= p.y;
    }

    public Position nearestAfterMove(Position pos, double move) {
        double xside = pos.x - x;
        double yside = pos.y - y;
        double hypo = Math.sqrt(xside * xside + yside * yside);
        return new Position(x + move * xside / hypo, y + move * yside / hypo);
    }

    public double angleTo(Position pos) {
        return Math.atan((pos.y - y) / (pos.x - x));
    }

    public boolean equals(Position pos) {
        return compareTo(pos) == 0;
    }


    public Position clone() {
        return new Position(x, y, angle);
    }

    @Override
    public int compareTo(Position pos) {
        return (int)((x*x + y*y - pos.x*pos.x - pos.y*pos.y) * 1e+6);
    }
}
