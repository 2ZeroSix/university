package ru.nsu.ccfit.lukin.dodge.details.missiles;

import ru.nsu.ccfit.lukin.dodge.DodgeException;
import ru.nsu.ccfit.lukin.dodge.Model;
import ru.nsu.ccfit.lukin.dodge.details.Explosion;
import ru.nsu.ccfit.lukin.dodge.details.Position;
import ru.nsu.ccfit.lukin.dodge.details.Detail;
import ru.nsu.ccfit.lukin.dodge.details.ships.Ship;

import java.util.stream.Stream;

/**
 * Created by dzs on 04.05.17.
 */
public class Missile extends Detail {
    private double damage;

    public Missile(Model model, Position position) throws DodgeException {
        this(model, position, 0, 0, 0);
    }

    public Missile(Model model, Position position, double speed, double circularSpeed, double damage) throws DodgeException {
        super(model, position, speed, circularSpeed);
        this.damage = damage;
    }

    public double getDamage() {
        return damage;
    }

    public Missile setDamage(double damage) {
        this.damage = damage;
        return this;
    }

    protected void hitIfTouched(Stream<Ship> ships) {
        ships.filter(ship -> {
            try {
                return isContains(position.nearestAfterMove(ship.getPosition(), getRadius()));
            } catch (Position.PositionException e) {
                return false;
            }
        }).forEach(ship -> {
            ship.harm(damage);
            destroy();
        });
    }

    public void move() {
        Model model = this.model.get();
        Position targetPosition = model.getPlayerShip().getPosition();
        try {
            setPosition(position.nearestAfterMove(targetPosition, speed, circularSpeed));
        } catch (Position.PositionException e) {
            destroy();
            return;
        }
        hitIfTouched(Stream.concat(model.getEnemiesShips().stream(),
                    Stream.<Ship>builder().add(model.getPlayerShip()).build()));
    }
}
