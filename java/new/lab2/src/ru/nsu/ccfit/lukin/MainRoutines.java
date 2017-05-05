package ru.nsu.ccfit.lukin;

import ru.nsu.ccfit.lukin.logoWorld.Interpreter;

import java.io.IOException;

/**
 * Run interpreter with default streams
 */
public class MainRoutines {
    public static void main(String[] args) throws IOException {
        Interpreter interpreter = new Interpreter();
        interpreter.run();
    }
}
