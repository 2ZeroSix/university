package ru.nsu.ccfit.lukin.dodge.details.missiles;

import ru.nsu.ccfit.lukin.dodge.DodgeException;
import ru.nsu.ccfit.lukin.dodge.Model;
import ru.nsu.ccfit.lukin.dodge.details.Position;

/**
 * Created by dzs on 10.05.17.
 */
public class UFOMissile extends Missile{
    public UFOMissile(Model model, Position position) throws DodgeException {
        super(model, position);
        setRadius(0.02);
        setSpeed(0.005);
        setCircularSpeed(Math.PI/64);
        setDamage(1000);
    }
}
