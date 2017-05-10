package ru.nsu.ccfit.lukin.dodge.components.ships;

import ru.nsu.ccfit.lukin.dodge.components.RotatableImageIcon;

import javax.imageio.ImageIO;
import java.io.IOException;

/**
 * Created by dzs on 10.05.17.
 */
public class UFOComponent extends RotatableImageIcon {
    public UFOComponent(double angle) throws IOException {
        super(ImageIO.read(UFOComponent.class.getResource("ufo.png")), angle);
    }
}
