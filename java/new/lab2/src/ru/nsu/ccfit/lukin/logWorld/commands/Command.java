package ru.nsu.ccfit.lukin.logWorld.commands;

import ru.nsu.ccfit.lukin.logWorld.Interpreter;

import java.util.Collection;

/**
 * Created by dzs on 22.03.17.
 */
public interface Command {
    void act(Interpreter.Context context, Collection<String> args) throws CommandException;
}
