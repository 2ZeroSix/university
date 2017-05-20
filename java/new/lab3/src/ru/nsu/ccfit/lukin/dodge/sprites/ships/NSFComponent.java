package ru.nsu.ccfit.lukin.dodge.sprites.ships;

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
public class NSFComponent extends Sprite {
    static {
        try {
            image = ImageIO.read(ABLComponent.class.getResource("nsf.png"));
        } catch (IOException e) {
            image = null;
        }
    }
    public NSFComponent() throws DodgeException {
        super(image);
    }
}
