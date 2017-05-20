package ru.nsu.ccfit.lukin.dodge;

import ru.nsu.ccfit.lukin.dodge.sprites.Sprite;
import ru.nsu.ccfit.lukin.dodge.sprites.SpriteFactory;
import ru.nsu.ccfit.lukin.dodge.details.Detail;
import ru.nsu.ccfit.lukin.dodge.details.Position;

import javax.swing.*;
import java.awt.*;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by dzs on 03.05.17.
 */
public class View extends JPanel implements Runnable {
    private final Controller controller;
    SpriteFactory dvf = new SpriteFactory();
    Map<Detail, Sprite> componentMap = new HashMap<>();
    Timer timer;

    public View(Controller controller) throws DodgeException {
        super(null);
        this.controller = controller;
//        setLayout(new FlowLayout());
//        setLayout(new OverlayLayout(this));
        controller.getModel().setView(this);
        timer = new Timer(333, actionEvent -> {
            try {
                controller.step();
            } catch (DodgeException e) {
                e.printStackTrace();
                stop();
            }
        });
    }

    public void add(Detail detail) throws DodgeException {
        Sprite component = dvf.get(detail);
        componentMap.put(detail, component);
        add(component);
        update(component, detail);
    }

    public void remove(Detail detail) {
        remove(componentMap.remove(detail));
    }

    private void updatePosition(Sprite component, Position position) {
        component.setAngle(position.getAngle());
        component.setBounds((int)(position.getX() - position.getRadius())*getWidth(),
                (int)(position.getY() - position.getRadius())*getHeight(),
                (int)(position.getRadius())*getWidth(),
                (int)(position.getRadius())*getHeight());
    }

    final public void update(Detail detail) throws DodgeException {
        Sprite component = componentMap.get(detail);
        if (component == null)  add(detail);
        else                    update(component, detail);
    }

    protected void update(Sprite component, Detail detail) {
        updatePosition(component, detail.getPosition());
        component.revalidate();
        component.repaint();
    }

    @Override
    public void run() {
        new Timer(33, act -> {
            try {
                controller.step();
            } catch(Controller.GameOverException e) {
                stop();
            } catch (DodgeException e) {
                e.printStackTrace();
            }
        }).start();
    }

    public void stop() {
        timer.stop();
    }
}
