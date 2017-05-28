package ru.nsu.ccfit.lukin.dodge.sprites.ships;

import ru.nsu.ccfit.lukin.dodge.DodgeException;
import ru.nsu.ccfit.lukin.dodge.sprites.Sprite;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.IOException;

/**
 * Created by dzs on 10.05.17.
 */
public class KSDComponent extends Sprite {
    private static BufferedImage image;
    static {
        try {
            image = ImageIO.read(ABLComponent.class.getResource("ksd.png"));
        } catch (IOException e) {
            image = null;
        }
    }
    public KSDComponent() throws DodgeException {
        super(image);
    }
}
