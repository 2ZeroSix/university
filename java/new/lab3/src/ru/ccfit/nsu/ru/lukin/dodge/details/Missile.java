package ru.ccfit.nsu.ru.lukin.dodge.details;

import ru.ccfit.nsu.ru.lukin.dodge.Model;

/**
 * Created by dzs on 04.05.17.
 */
public class Missile extends RoundDetail {
    private double damage;
    public Missile(Model model, Position position, double radius, double angle, double speed, double circularSpeed){
        super(model, position, radius, angle, speed, circularSpeed);
    }
    public void move() {
        Model model = this.model.get();
        Position targetPosition = model.getPlayerShip().getPosition();
        setPosition(new Position(position.x + speed * Math.cos(angle), position.y + speed * Math.sin(angle)));
        double preferredAngle = Math.atan((targetPosition.y - position.y)
                                        / (targetPosition.x - position.x));
        angle = circularSpeed >= Math.abs(preferredAngle - angle)
                ? preferredAngle
                : angle + circularSpeed * Math.signum(angle - preferredAngle);
        model.getEnemiesShips().stream().forEach(armedShipController -> );
    }
}
