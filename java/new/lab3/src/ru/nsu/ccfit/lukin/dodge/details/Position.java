package ru.nsu.ccfit.lukin.dodge.details;

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
        this.x = x <= 1 && x >= 0 ? x : 0;
        this.y = y <= 1 && y >= 0 ? y : 0;
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

    public double getAngle() {
        return angle;
    }

    public Position setAngle(double angle) {
        this.angle = angle;
        return this;
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
        return Math.abs(x - pos.x) <= 1e-6 && Math.abs(y - pos.y) <= 1e-6 ? 0 : (int)Math.signum(x + y - pos.x - pos.y);
    }
}
