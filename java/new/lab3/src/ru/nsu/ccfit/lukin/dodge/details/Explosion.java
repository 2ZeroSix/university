package ru.nsu.ccfit.lukin.dodge.details;

import ru.nsu.ccfit.lukin.dodge.DodgeException;
import ru.nsu.ccfit.lukin.dodge.Model;

/**
 * Created by dzs on 12.05.17.
 */
public class Explosion extends Detail {
    int timeToLive = 60;
    int tick = 0;
    public Explosion(Model model, Position position) throws DodgeException {
        super(model, position, 0, 0);
    }

    public int getTimeToLive() {
        return timeToLive;
    }

    public void setTimeToLive(int timeToLive) {
        this.timeToLive = timeToLive;
    }

    @Override
    public void destroy() {
        if (!isDestroyed()) {
            destroyed = true;
            getModel().getView().remove(this);
        }

    }

    @Override
    public void move() {
        if (++tick % timeToLive == 0) destroy();
    }
}
