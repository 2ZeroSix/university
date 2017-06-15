package ru.nsu.ccfit.lukin;

import ru.nsu.ccfit.lukin.dodge.Dodge;
import ru.nsu.ccfit.lukin.dodge.DodgeException;
import ru.nsu.ccfit.lukin.dodge.Model;
import ru.nsu.ccfit.lukin.dodge.details.Position;
import ru.nsu.ccfit.lukin.dodge.details.ships.Ship;
import ru.nsu.ccfit.lukin.dodge.sprites.Sprite;
import ru.nsu.ccfit.lukin.dodge.sprites.SpriteFactory;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.image.ImageProducer;
import java.io.IOException;

/**
 * start game
 */
public class Main {
    static JFrame frame = new JFrame();
    public static void main(String[] args) throws DodgeException, IOException {
        Dodge dodge = new Dodge();
        dodge.run();
//        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//        Position position = new Position(.7, .7, Math.PI / 2);
//        position.setRadius(.5);
//        Sprite sprite = new Sprite(ImageIO.read(Sprite.class.getResource("ships/ufo.png")),
//                position);
//        JPanel panel = new JPanel(null);
//        frame.add(panel);
//        panel.setPreferredSize(new Dimension(250, 250));
//        panel.add(sprite);
//        frame.addMouseListener(new MouseAdapter() {
//            @Override
//            public void mousePressed(MouseEvent e) {
//                sprite.setAngle(sprite.getAngle() + Math.PI/8);
//                frame.repaint();
//            }
//        });
//        frame.pack();
//        frame.setVisible(true);
    }
}
