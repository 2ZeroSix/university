package ru.nsu.ccfit.lukin.dodge.sprites;

import ru.nsu.ccfit.lukin.dodge.DodgeException;
import ru.nsu.ccfit.lukin.dodge.sprites.ships.ABLComponent;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.IOException;

/**
 * Created by dzs on 13.05.17.
 */
public class ExplosionComponent extends Sprite {
    private static BufferedImage image;
    static {
        try {
            image = ImageIO.read(ExplosionComponent.class.getResource("explosion.png"));
        } catch (IOException e) {
            image = null;
        }
    }
    public ExplosionComponent() throws DodgeException {
        super(image);
    }
}
