package ru.ccfit.nsu.ru.lukin.dodge.details;

import ru.ccfit.nsu.ru.lukin.dodge.Model;

import java.util.stream.Stream;

/**
 * Created by dzs on 04.05.17.
 */
public class Missile extends RoundDetail {
    private double damage;
    public Missile(Model model, Position position, double radius, double angle, double speed, double circularSpeed){
        super(model, position, radius, angle, speed, circularSpeed);
    }

    protected void hitIfTouched(Stream<Ship> ships) {
        ships.filter(ship -> isContains(position.nearestAfterMove(ship.position, radius)))
                .forEach(ship -> ship.harm(damage));
    }

    public void move() {
        Model model = this.model.get();
        Position targetPosition = model.getPlayerShip().getPosition();
        setPosition(new Position(position.x + speed * Math.cos(angle), position.y + speed * Math.sin(angle)));
        double preferredAngle = position.bestAngleTo(targetPosition);
        angle = circularSpeed >= Math.abs(preferredAngle - angle)
                ? preferredAngle
                : angle + circularSpeed * Math.signum(angle - preferredAngle);
    }
}
