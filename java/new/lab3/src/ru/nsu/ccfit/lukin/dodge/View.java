package ru.nsu.ccfit.lukin.dodge;

import ru.nsu.ccfit.lukin.dodge.sprites.Sprite;
import ru.nsu.ccfit.lukin.dodge.sprites.SpriteFactory;
import ru.nsu.ccfit.lukin.dodge.details.Detail;
import ru.nsu.ccfit.lukin.dodge.details.Position;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by dzs on 03.05.17.
 */
public class View extends JPanel {
    private final Controller controller;
    private final SpriteFactory spriteFactory = new SpriteFactory();
    private final Map<Detail, Sprite> spriteMap = new HashMap<>();
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
        addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                super.keyPressed(e);
            }
        });
    }

    private void add(Detail detail) throws DodgeException {
        Sprite sprite = spriteFactory.get(detail);
        spriteMap.put(detail, sprite);
        add(sprite);
        update(sprite, detail);
    }

    public void remove(Detail detail) {
        Sprite sprite = spriteMap.remove(detail);
        sprite.setVisible(false);
        remove(sprite);
//        revalidate();
        repaint();
    }


    final public void update(Detail detail) throws DodgeException {
        Sprite sprite = spriteMap.get(detail);
        if (sprite == null) add(detail);
        else                update(sprite, detail);
    }

    private void update(Sprite sprite, Detail detail) {
        sprite.setPosition(detail.getPosition());
        revalidate();
        repaint();
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
