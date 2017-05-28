package ru.nsu.ccfit.lukin.dodge.details;

import ru.nsu.ccfit.lukin.dodge.DodgeException;

/**
 * Created by dzs on 03.05.17.
 */
public class Position implements Cloneable, Comparable<Position> {
    private double x;
    private double y;
    private double angle;
    private double radius;

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public static class PositionException extends DodgeException {
        public PositionException() {
        }
        public PositionException(String var1) {
            super(var1);
        }
        public PositionException(String var1, Throwable var2) {
            super(var1, var2);
        }
        public PositionException(Throwable var1) {
            super(var1);
        }
        public PositionException(String var1, Throwable var2, boolean var3, boolean var4) {
            super(var1, var2, var3, var4);
        }
    }

    public Position() {
        try {   setX(0); setY(0);
        } catch (PositionException ignore) {}
        setAngle(Math.PI/2.);
    }

    public Position(double x, double y) throws PositionException {
        this(x, y, Math.PI / 2.);
    }

    public Position(double x, double y, double angle) throws PositionException {
        setX(x);
        setY(y);
        setAngle(angle);
    }

    public double getX() {
        return x;
    }

    public void setX(double x) throws PositionException {
        if (0 <= x && x <= 1)
            this.x = x;
        else throw new PositionException("wrong x");
    }

    public double getY() {
        return y;
    }

    public void setY(double y) throws PositionException {
        if (0 <= y && y <= 1)
            this.y = y;
        else throw new PositionException("wrong y");
    }

    public double getAngle() {
        return angle;
    }

    public Position setAngle(double angle) {
        this.angle = angle;
        return this;
    }

    public Position nearestAfterMove(Position pos, double move) throws PositionException {
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


    public Position clone() throws CloneNotSupportedException {
        try {
            return new Position(x, y, angle);
        } catch (PositionException e) {
            throw new CloneNotSupportedException("Can't create new Position");
        }
    }

    @Override
    public int compareTo(Position pos) {
        return Math.abs(x - pos.x) <= 1e-6 && Math.abs(y - pos.y) <= 1e-6 ? 0 : (int)Math.signum(x + y - pos.x - pos.y);
    }
}
