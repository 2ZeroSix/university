package ru.nsu.ccfit.lukin.dodge.sprites.missiles;

import ru.nsu.ccfit.lukin.dodge.DodgeException;
import ru.nsu.ccfit.lukin.dodge.sprites.RotatableImageIcon;
import ru.nsu.ccfit.lukin.dodge.sprites.Sprite;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.image.BufferedImage;
import java.io.IOException;

/**
 * Created by dzs on 10.05.17.
 */
public class KSDComponent extends Sprite {
    static {
        try {
            image = ImageIO.read(ru.nsu.ccfit.lukin.dodge.sprites.ships.ABLComponent.class.getResource("ksd.png"));
        } catch (IOException e) {
            image = null;
        }
    }
    public KSDComponent() throws DodgeException {
        super(image);
    }
}
