package ru.nsu.ccfit.lukin.dodge.components.missiles;

import ru.nsu.ccfit.lukin.dodge.components.RotatableImageIcon;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.IOException;

/**
 * Created by dzs on 10.05.17.
 */
public class ABLComponent extends RotatableImageIcon {
    public ABLComponent(double angle) throws IOException {
        super(ImageIO.read(ABLComponent.class.getResource("abl-missle.png")), angle);
    }
}
