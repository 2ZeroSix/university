package ru.nsu.ccfit.lukin;

import ru.nsu.ccfit.lukin.logWorld.Interpreter;

import java.io.*;

/**
 * Created by dzs on 16.03.17.
 */
public class MainRoutines {
    public static void main(String[] args) {
        Interpreter interpreter = null;
        interpreter = new Interpreter();
        interpreter.run();
    }
}
