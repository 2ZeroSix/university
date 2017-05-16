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
        this(model, position, 0, 0, 0, 0);
    }

    public Missile(Model model, Position position, double radius, double speed, double circularSpeed, double damage) throws DodgeException {
        super(model, position, radius, speed, circularSpeed);
        this.damage = damage;
    }

    @Override
    public void destroy() {
        super.destroy();
        Model model = getModel();
        try {
            model.add(new Explosion(getModel(), position));
        } catch (DodgeException e) {
            e.printStackTrace();
        }
        model.getView().remove(this);
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
                return isContains(position.nearestAfterMove(ship.getPosition(), radius));
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
            setPosition(new Position(position.getX() + speed * Math.cos(position.getAngle()),
                                    position.getY() + speed * Math.sin(position.getAngle())));
        } catch (Position.PositionException e) {
            destroy();
            return;
        }
        double preferredAngle = position.angleTo(targetPosition);
        position.setAngle(circularSpeed >= Math.abs(preferredAngle - position.getAngle())
                ? preferredAngle
                : position.getAngle() + circularSpeed * Math.signum(position.getAngle() - preferredAngle));
        hitIfTouched(Stream.concat(model.getEnemiesShips().stream(),
                    Stream.<Ship>builder().add(model.getPlayerShip()).build()));
    }
}
