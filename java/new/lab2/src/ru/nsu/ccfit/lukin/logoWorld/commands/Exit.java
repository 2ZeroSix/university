package ru.nsu.ccfit.lukin.logoWorld.commands;

import ru.nsu.ccfit.lukin.logoWorld.Interpreter;

import java.util.Collection;

/**
 * Created by dzs on 26.04.17.
 */
public class Exit implements Command {
    @Override
    public void act(Interpreter.Context context, Collection<String> args) throws CommandException {
        context.stop();
    }
}
