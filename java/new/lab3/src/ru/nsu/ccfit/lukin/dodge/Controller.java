package ru.nsu.ccfit.lukin.dodge;

import ru.nsu.ccfit.lukin.dodge.details.Detail;
import ru.nsu.ccfit.lukin.dodge.details.missiles.Missile;
import ru.nsu.ccfit.lukin.dodge.details.ships.ArmedShip;
import ru.nsu.ccfit.lukin.dodge.details.ships.EnemyShip;
import ru.nsu.ccfit.lukin.dodge.details.ships.Ship;
import ru.nsu.ccfit.lukin.dodge.details.ships.ShipFactory;

import java.util.function.Consumer;
import java.util.function.Function;
import java.util.stream.Stream;

/**
 * Created by dzs on 03.05.17.
 */
public class Controller {
    public enum Difficulty {
        EASY(10),
        MEDIUM(5),
        HARD(3);
        private int enemiesAppearanceRate;
        Difficulty(int enemiesAppearanceRate) {
            this.enemiesAppearanceRate = enemiesAppearanceRate;
        }
        public int getEnemiesAppearanceRate() {
            return enemiesAppearanceRate;
        }
    }
    private int updateRate = 30;
    private int step = 0;
    private Model model;
    private Difficulty difficulty;
    private boolean moving;
    final private ShipFactory shipFactory;

    public static class GameOverException extends DodgeException {
        public GameOverException() {
        }
        public GameOverException(String var1) {
            super(var1);
        }
        public GameOverException(String var1, Throwable var2) {
            super(var1, var2);
        }
        public GameOverException(Throwable var1) {
            super(var1);
        }
        public GameOverException(String var1, Throwable var2, boolean var3, boolean var4) {
            super(var1, var2, var3, var4);
        }
    }

    public Controller(Model model, Difficulty difficulty) {
        this.model = model;
        this.difficulty = difficulty;
        shipFactory = new ShipFactory(model);
    }

    public Model getModel() {
        return model;
    }

    public synchronized void step() throws DodgeException {
        Consumer<Detail> consumer = detail -> {
            try {
                detail.act();
            } catch (DodgeException e) {
                e.printStackTrace();
            }
        };
        for (ArmedShip armedShip : model.getEnemiesShips()) {
            consumer.accept(armedShip);
        }
        model.getEnemiesShips().removeIf(Detail::isDestroyed);
        for (Missile missile : model.getMissiles()) {
            consumer.accept(missile);
        }
        model.getMissiles().removeIf(Detail::isDestroyed);
        for (Detail detail : model.getDetails()) {
            consumer.accept(detail);
        }
        model.getDetails().removeIf(Detail::isDestroyed);

        movePlayer();
        if (step++ % (updateRate * difficulty.getEnemiesAppearanceRate()) == 0) {
            model.addEnemyShip((ArmedShip)shipFactory.getEnemy());
        }
    }

    private void movePlayer() throws DodgeException {
        if (moving) {
            Ship ship = model.getPlayerShip();
            ship.act();
        }
    }

    public void startMove(int direction) {
        Ship ship = model.getPlayerShip();
        if (moving)
            ship.setPreferredAngle(Math.PI / 2 * direction);
        else
            ship.setPreferredAngle(
                    (ship.getPreferredAngle() +  Math.PI / 2 * direction) / 2);
        moving = true;
    }

    public void stopMove(int direction) {
        Ship ship = model.getPlayerShip();
        if (ship.getPreferredAngle() - Math.PI / 2 * direction <= 1E-6)
            moving = false;
        else

        moving = false;
    }
}
