package ru.nsu.ccfit.lukin.dodge.sprites.missiles;

import ru.nsu.ccfit.lukin.dodge.DodgeException;
import ru.nsu.ccfit.lukin.dodge.sprites.Sprite;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.IOException;

/**
 * Created by dzs on 10.05.17.
 */
public class BOMBComponent extends Sprite {
    private static BufferedImage image;
    static {
        try {
            image = ImageIO.read(ru.nsu.ccfit.lukin.dodge.sprites.ships.ABLComponent.class.getResource("bomb.png"));
        } catch (IOException e) {
            image = null;
        }
    }
    public BOMBComponent() throws DodgeException {
        super(image);
    }
}
