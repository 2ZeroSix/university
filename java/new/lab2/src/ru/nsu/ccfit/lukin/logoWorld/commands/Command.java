package ru.nsu.ccfit.lukin.logoWorld.commands;

import ru.nsu.ccfit.lukin.logoWorld.Interpreter;

import java.util.Collection;

/**
 * Basic interface for commands
 */
public interface Command {
    /**
     * @param context context of work
     * @param args arguments given to command
     * @throws CommandException
     */
    void act(Interpreter.Context context, Collection<String> args) throws CommandException;
}
