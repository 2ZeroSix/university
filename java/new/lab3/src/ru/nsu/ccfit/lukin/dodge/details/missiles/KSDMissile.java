package ru.nsu.ccfit.lukin.dodge.details.missiles;

import ru.nsu.ccfit.lukin.dodge.DodgeException;
import ru.nsu.ccfit.lukin.dodge.Model;
import ru.nsu.ccfit.lukin.dodge.details.Position;

/**
 * Created by dzs on 10.05.17.
 */
public class KSDMissile extends Missile{
    public KSDMissile(Model model, Position position) throws DodgeException {
        super(model, position);
        setRadius(0.01);
        setSpeed(0.01);
        setCircularSpeed(Math.PI/16);
        setDamage(150);
    }
}
