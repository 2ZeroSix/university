package ru.nsu.ccfit.lukin;

import ru.nsu.ccfit.lukin.dodge.Dodge;
import ru.nsu.ccfit.lukin.dodge.DodgeException;
import ru.nsu.ccfit.lukin.dodge.Model;
import ru.nsu.ccfit.lukin.dodge.details.Position;
import ru.nsu.ccfit.lukin.dodge.details.ships.ABLShip;
import ru.nsu.ccfit.lukin.dodge.details.ships.EnemyShip;
import ru.nsu.ccfit.lukin.dodge.details.ships.Ship;
import ru.nsu.ccfit.lukin.dodge.sprites.RotatableImageIcon;
import ru.nsu.ccfit.lukin.dodge.sprites.Sprite;
import ru.nsu.ccfit.lukin.dodge.sprites.SpriteFactory;
import ru.nsu.ccfit.lukin.dodge.sprites.ships.UFOComponent;

import javax.imageio.IIOImage;
import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.io.IOException;

/**
 * run game
 */
public class Main {
    static JFrame frame = new JFrame();
    public static void main(String[] args) throws DodgeException, IOException {
        Dodge dodge = new Dodge();
        dodge.run();
        Model model = new Model();
        Ship ship = model.getPlayerShip();
        SpriteFactory factory = new SpriteFactory();
        Sprite component = factory.get(ship);
        Position position = ship.getPosition();
        component.setAngle(position.getAngle());
        frame.setPreferredSize(new Dimension(250, 250));
        component.setBounds((int)(position.getX() - position.getRadius())*frame.getWidth(),
                (int)(position.getY() - position.getRadius())*frame.getHeight(),
                (int)(position.getX() + position.getRadius())*frame.getWidth(),
                (int)(position.getY() + position.getRadius())*frame.getHeight());
//        JPanel panel = new JPanel(null);
//        frame.add(panel);
//        panel.setPreferredSize(new Dimension(250, 250));
////        panel.add(new UFOComponent());
//        RotatableImageIcon icon = new RotatableImageIcon(ImageIO.read(Main.class.getResource("dodge/sprites/explosion.png")));
//        JLabel image = new JLabel(icon);
//        icon.setImageObserver(image);
//        image.setBounds(10, 10, 128, 128);
//        image.repaint();
//        panel.add(image);
//        frame.pack();
//        frame.setVisible(true);
    }
}
