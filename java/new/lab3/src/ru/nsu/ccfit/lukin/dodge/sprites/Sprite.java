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
public class Sprite extends ImageIcon {
    private Position pos;
    public Sprite(BufferedImage bi) {
        this(bi, new Position());
    }

    public Sprite(BufferedImage bi, Position pos) {
        super(bi);
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
    public synchronized void paintIcon(Component component, Graphics graphics, int i, int i1) {
        ImageObserver observer = component;
        if(this.getImageObserver() != null) {
            observer = this.getImageObserver();
        }
        double angle = -this.pos.getAngle();
        double sin = Math.abs(Math.sin(angle)), cos = Math.abs(Math.cos(angle));
        int w = getImage().getWidth(observer), h = getImage().getHeight(observer);
        int neww = (int)Math.floor(w*cos+h*sin), newh = (int) Math.floor(h * cos + w * sin);
        Graphics2D g = ((Graphics2D)graphics);//.rotate(Math.PI/2 - angle);
        System.out.println(component.getWidth() + " " + component.getHeight());
        System.out.println(getImage().getWidth(observer) + " " + getImage().getHeight(observer));
//        g.translate((neww - w) / 2, (newh - h) / 2);
        g.rotate(angle, w / 2, h / 2);
        g.scale(2*pos.getRadius()*(double)component.getWidth() / (double)getImage().getWidth(observer),
                2*pos.getRadius()*(double)component.getHeight() / (double)getImage().getHeight(observer));
//        g.translate(-(neww - w) / 2, -(newh - h) / 2);
//        g.translate((pos.getX() - pos.getRadius())*component.getWidth(),
//                (pos.getY() - pos.getRadius())*component.getHeight());
//        g.drawImage(getImage(), 0, 0, observer);
        super.paintIcon(component, graphics, 0, 0);
    }
//    public static BufferedImage rotate(BufferedImage image, Graphics graphics, double angle) {
//        double sin = Math.abs(Math.sin(angle)), cos = Math.abs(Math.cos(angle));
//        int w = image.getWidth(), h = image.getHeight();
//        int neww = (int)Math.floor(w*cos+h*sin), newh = (int) Math.floor(h * cos + w * sin);
//        GraphicsConfiguration gc = getDefaultConfiguration();
//        BufferedImage result = gc.createCompatibleImage(neww, newh, Transparency.TRANSLUCENT);
//        Graphics2D g = result.createGraphics();
//        g.translate((neww - w) / 2, (newh - h) / 2);
//        g.rotate(angle, w / 2, h / 2);
//        g.drawRenderedImage(image, null);
//        g.dispose();
//        return result;
//    }
//
//    private static GraphicsConfiguration getDefaultConfiguration() {
//        GraphicsEnvironment ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
//        GraphicsDevice gd = ge.getDefaultScreenDevice();
//        return gd.getDefaultConfiguration();
//    }

}
