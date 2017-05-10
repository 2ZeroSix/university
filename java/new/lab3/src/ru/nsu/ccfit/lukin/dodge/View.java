package ru.nsu.ccfit.lukin.dodge;

import ru.nsu.ccfit.lukin.dodge.components.DetailViewFactory;
import ru.nsu.ccfit.lukin.dodge.details.Detail;
import ru.nsu.ccfit.lukin.dodge.details.Position;

import javax.swing.*;
import java.awt.*;
import java.util.Map;

/**
 * Created by dzs on 03.05.17.
 */
public class View extends JPanel {
    DetailViewFactory dvf = new DetailViewFactory();
    Map<Detail, JComponent> componentMap;

    public View(Controller controller) {
        super();
        setLayout(new OverlayLayout(this));
    }

    public void add(Detail detail) throws DodgeException {
        JComponent component = dvf.get(detail);
        componentMap.put(detail, component);
        update(component, detail);
    }

    private void updatePosition(JComponent component, Position position) {
        ((Graphics2D)component.getGraphics()).rotate(position.getAngle());
    }

    public void update(Detail detail) {
        update(componentMap.get(detail), detail);
    }

    protected void update(JComponent component, Detail detail) {
        updatePosition(component, detail.getPosition());
    }
}
