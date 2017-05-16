package ru.nsu.ccfit.lukin.dodge.sprites;

import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.awt.image.ImageObserver;
import java.io.IOException;

/**
 * Created by dzs on 10.05.17.
 */
public class RotatableImageIcon extends ImageIcon {
    double angle;

    public RotatableImageIcon(BufferedImage bi) throws IOException {
        this(bi, Math.PI/2);
    }

    public RotatableImageIcon(BufferedImage bi,  double angle) throws IOException {
        super(bi);
        this.angle = angle;
    }

    public double getAngle() {
        return angle;
    }

    public RotatableImageIcon setAngle(double angle) {
        this.angle = angle;
        return this;
    }

    @Override
    public synchronized void paintIcon(Component component, Graphics graphics, int i, int i1) {
        ImageObserver observer = component;
        if(this.getImageObserver() != null) {
            observer = this.getImageObserver();
        }
        double angle = -this.angle;
        double sin = Math.abs(Math.sin(angle)), cos = Math.abs(Math.cos(angle));
        int w = getImage().getWidth(observer), h = getImage().getHeight(observer);
        int neww = (int)Math.floor(w*cos+h*sin), newh = (int) Math.floor(h * cos + w * sin);
        Graphics2D g = ((Graphics2D)graphics);//.rotate(Math.PI/2 - angle);
        g.translate((neww - w) / 2, (newh - h) / 2);
        g.rotate(angle, w / 2, h / 2);
        super.paintIcon(component, graphics, i, i1);
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
