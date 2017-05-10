package ru.nsu.ccfit.lukin.dodge.components.ships;

import ru.nsu.ccfit.lukin.dodge.components.RotatableImageIcon;

import javax.imageio.ImageIO;
import java.io.IOException;

/**
 * Created by dzs on 10.05.17.
 */
public class KSDComponent extends RotatableImageIcon {
    public KSDComponent(double angle) throws IOException {
        super(ImageIO.read(KSDComponent.class.getResource("ksd.png")), angle);
    }
}
