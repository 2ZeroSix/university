package ru.nsu.ccfit.lukin.logoWorld.commands;

import ru.nsu.ccfit.lukin.logoWorld.Interpreter;

import java.util.Collection;

/**
 * command to exit from interpreter
 * Doesn't expect arguments
 */
public class Exit implements Command {
    @Override
    public void act(Interpreter.Context context, Collection<String> args) throws CommandException {
        context.stop();
    }
}
