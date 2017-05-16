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
    private static Map<String, Class<? extends Sprite>> components = new HashMap<>();

    static {
        Properties props = new Properties();
        try {
            props.load(SpriteFactory.class.getResourceAsStream("DetailViewFactory.prop"));
        } catch (IOException e) {
            e.printStackTrace();
        }
        props.stringPropertyNames().forEach(str -> {
            try {
                components.put(str, (Class<? extends Sprite>) Class.forName(props.getProperty(str)));
            } catch (ClassNotFoundException e) {
                e.printStackTrace();
            }
        });
    }

    public Sprite get(Detail detail) throws DodgeException {
        Sprite component= null;
        try {
            component = components.get(detail.getClass().getName()).newInstance();
            if (component == null)
                throw new DodgeException("Can't find component for detail: "
                                            + detail.getClass().getName());
        } catch (Throwable e) {
            if (e instanceof DodgeException) throw (DodgeException) e;
            throw new DodgeException("Can't find component for detail: "
                                        + detail.getClass().getName(), e);
        }
        return component;
    }
}
