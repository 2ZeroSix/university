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
public class View extends JPanel {
    private final Controller controller;
    private final SpriteFactory spriteFactory = new SpriteFactory();
    private final Map<Detail, Sprite> componentMap = new HashMap<>();
    private final Timer timer;

    public View(Controller controller) throws DodgeException {
        super(null);
        this.controller = controller;
        setBackground(Color.CYAN);
        controller.getModel().setView(this);
        timer = new Timer(33, actionEvent -> {
            try {
                this.controller.step();
            } catch (Controller.GameOverException e) {
                View.this.stop();
            } catch (DodgeException e) {
                e.printStackTrace();
                View.this.stop();
            }
        });
    }

    public void add(Detail detail) throws DodgeException {
//        Sprite component = spriteFactory.get(detail);
//        componentMap.put(detail, component);
//        add(component);
//        update(component, detail);
    }

    public void remove(Detail detail) {
//        remove(componentMap.remove(detail));
    }

    private void updatePosition(Sprite sprite, Position position) {
//        sprite.setAngle(position.getAngle());
//        sprite.setLocation(new Point((int)(position.getX() - position.getRadius())*getWidth(),
//                (int)(position.getY() - position.getRadius())*getHeight()));
    }

    final public void update(Detail detail) throws DodgeException {
        Sprite component = componentMap.get(detail);
        if (component == null)  add(detail);
        else                    update(component, detail);
    }

    protected void update(Sprite component, Detail detail) {
//        updatePosition(component, detail.getPosition());
//        // TODO
//        component.revalidate();
//        component.repaint();
//        revalidate();
//        repaint();
    }

    public void start() {
        setVisible(true);
        timer.start();
    }

    public void stop() {
        timer.stop();
    }

    public Controller getController() {
        return controller;
    }
}
