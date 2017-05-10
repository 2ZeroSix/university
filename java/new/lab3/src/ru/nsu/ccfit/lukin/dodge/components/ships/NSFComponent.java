package ru.nsu.ccfit.lukin.dodge.components.ships;

import ru.nsu.ccfit.lukin.dodge.components.RotatableImageIcon;

import javax.imageio.ImageIO;
import java.io.IOException;

/**
 * Created by dzs on 10.05.17.
 */
public class NSFComponent extends RotatableImageIcon {
    public NSFComponent(double angle) throws IOException {
        super(ImageIO.read(NSFComponent.class.getResource("nsf.png")), angle);
    }
}
