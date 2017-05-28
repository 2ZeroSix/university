package ru.nsu.ccfit.lukin.dodge.sprites;

import ru.nsu.ccfit.lukin.dodge.DodgeException;
import ru.nsu.ccfit.lukin.dodge.details.Detail;

import javax.swing.*;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Properties;

/**
 * Created by dzs on 09.05.17.
 */
public class SpriteFactory {
    private final static Map<String, Class<? extends Sprite>> components = new HashMap<>();

    static {
        Properties props = new Properties();
        try {
            props.load(SpriteFactory.class.getResourceAsStream("SpriteFactory.prop"));
        } catch (IOException e) {
            e.printStackTrace();
        }
        props.stringPropertyNames().forEach(str -> {
            try {
                Class spriteClass = Class.forName(props.getProperty(str));
                if (Sprite.class.isAssignableFrom(spriteClass))
                    components.put(str, (Class<? extends Sprite>) spriteClass);
                else
                    System.err.println("class \""
                            + props.getProperty(str)
                            + "\" isn't inherited from Sprite");
            } catch (ClassNotFoundException e) {
                e.printStackTrace();
            }
        });
    }

    public Sprite get(Detail detail) throws DodgeException {
        Class<? extends Sprite> componentClass = null;
        try {
            componentClass = components.getOrDefault(detail.getClass().getName(), null);
            if (componentClass == null)
                throw new DodgeException("Can't find component for detail: "
                                            + detail.getClass().getName());
            return componentClass.newInstance();
        } catch (Throwable e) {
            if (e instanceof DodgeException) throw (DodgeException) e;
            throw new DodgeException("Can't instantiate sprite: "
                                        + componentClass.getName(), e);
        }
    }
}
