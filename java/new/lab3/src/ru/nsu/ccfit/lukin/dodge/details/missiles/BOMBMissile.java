package ru.nsu.ccfit.lukin.dodge.details.missiles;

import ru.nsu.ccfit.lukin.dodge.DodgeException;
import ru.nsu.ccfit.lukin.dodge.Model;
import ru.nsu.ccfit.lukin.dodge.details.Position;

/**
 * Created by dzs on 10.05.17.
 */
public class BOMBMissile extends Missile{
    public BOMBMissile(Model model, Position position) throws DodgeException {
        super(model, position);
        setRadius(0.005);
        setSpeed(0.01);
        setCircularSpeed(Math.PI/32);
        setDamage(100);
    }
}
