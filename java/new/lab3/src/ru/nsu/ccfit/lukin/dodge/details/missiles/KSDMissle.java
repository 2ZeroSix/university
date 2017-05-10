package ru.nsu.ccfit.lukin.dodge.details.missiles;

import ru.nsu.ccfit.lukin.dodge.Model;
import ru.nsu.ccfit.lukin.dodge.details.Position;

/**
 * Created by dzs on 10.05.17.
 */
public class KSDMissle extends Missile{
    public KSDMissle(Model model, Position position) {
        super(model, position);
        setRadius(0.01);
        setSpeed(0.01);
        setCircularSpeed(Math.PI/16);
        setDamage(150);
    }
}
