package ru.nsu.ccfit.lukin.dodge.sprites;

import ru.nsu.ccfit.lukin.dodge.DodgeException;
import ru.nsu.ccfit.lukin.dodge.sprites.ships.ABLComponent;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.image.BufferedImage;
import java.io.IOException;

/**
 * Created by dzs on 12.05.17.
 */
public class Sprite extends JLabel {
    protected static BufferedImage image;
    protected RotatableImageIcon rotatableImageIcon;
    public Sprite(BufferedImage image) throws DodgeException {
        super();
        if (image == null) throw new DodgeException("can't find image");
        try {
            rotatableImageIcon = new RotatableImageIcon(image, 0);
            setIcon(rotatableImageIcon);
        } catch (IOException e) {
            throw new DodgeException("can't create component", e);
        }
    }
    public void setAngle(double angle) {
        rotatableImageIcon.setAngle(angle);
    }
    public double getAngle() {
        return rotatableImageIcon.getAngle();
    }
}
