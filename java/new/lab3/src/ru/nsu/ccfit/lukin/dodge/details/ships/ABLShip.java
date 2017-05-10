package ru.nsu.ccfit.lukin.dodge.details.ships;

import ru.nsu.ccfit.lukin.dodge.Model;
import ru.nsu.ccfit.lukin.dodge.details.Position;
import ru.nsu.ccfit.lukin.dodge.details.missiles.ABLMissile;

/**
 * Created by dzs on 10.05.17.
 */
public class ABLShip extends ArmedShip {

    public ABLShip(Model model) {
        super(model);
        double rand = Math.random();
        if (rand > 0.75)        setPosition(new Position(Math.random(), 0, -Math.PI/2));
        else if (rand > 0.5)    setPosition(new Position(Math.random(), 1, Math.PI/2));
        else if (rand > 0.25)   setPosition(new Position(0, Math.random(), 0));
        else                    setPosition(new Position(1, Math.random(), Math.PI));
        setRadius(0.1);
        setSpeed(0.005);
        setCircularSpeed(Math.PI/16);
        setHealth(1000);
        setMissileClass(ABLMissile.class);
    }
}
