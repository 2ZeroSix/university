package ru.nsu.ccfit.lukin.dodge;

import ru.nsu.ccfit.lukin.dodge.details.Detail;
import ru.nsu.ccfit.lukin.dodge.details.ships.ArmedShip;
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
//        Function<Void, Detail> fun = new
        Consumer<Detail> consumer = detail -> {
            try {
                detail.act();
            } catch (DodgeException e) {
                e.printStackTrace();
            }
        };
        model.getEnemiesShips().stream().forEach(consumer);
        model.getMissiles().stream().forEach(consumer);
        model.getDetails().stream().forEach(consumer);

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

    public void startMove(double angle) {
        Ship ship = model.getPlayerShip();
        ship.setPreferredAngle(angle);
        moving = true;
    }

    public void stopMove(double angle) {
        moving = false;
    }
}
