package ru.nsu.ccfit.lukin.dodge.sprites;

import ru.nsu.ccfit.lukin.dodge.details.Position;

import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.awt.image.ImageObserver;
import java.io.IOException;

/**
 * Created by dzs on 10.05.17.
 */
public class Sprite extends JLabel {
    private Position pos;
    private BufferedImage bi;
    public Sprite(BufferedImage bi) {
        this(bi, new Position());
    }

    public Sprite(BufferedImage bi, Position pos) {
        setBounds(new Rectangle(0,0,1,1));
        this.bi = bi;
        this.pos = pos;
    }

    public void setPosition(Position pos) {
        this.pos = pos;
    }
    public Position getPosition() {
        return pos;
    }
    public double getAngle() {
        return pos.getAngle();
    }

    public Sprite setAngle(double angle) {
        pos.setAngle(angle);
        return this;
    }

    @Override
    public void paint(Graphics g) {
        setBounds(getParent().getBounds());
        super.paint(g);
    }

    @Override
    protected void paintComponent(Graphics g1) {
        super.paintComponent(g1);
        double angle = Math.PI - this.pos.getAngle();
        int w = bi.getWidth(null), h = bi.getHeight(null);
        int pw = getWidth(), ph = getHeight();

        Graphics2D g = (Graphics2D)g1;
        g.translate((pos.getX() - pos.getRadius())*pw,
                (pos.getY() - pos.getRadius())*ph);
        g.scale(2*pos.getRadius()*pw / w,
                2*pos.getRadius()*pw / h);
        g.rotate(angle, w/2, h/2);
        g.drawImage(bi, 0, 0, this);
    }
}
