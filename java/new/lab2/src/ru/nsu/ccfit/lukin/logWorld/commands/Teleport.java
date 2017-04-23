package ru.nsu.ccfit.lukin.logWorld.commands;

import ru.nsu.ccfit.lukin.logWorld.Interpreter;
import ru.nsu.ccfit.lukin.logWorld.Model;

import java.util.Collection;
import java.util.Iterator;

/**
 * Created by dzs on 22.03.17.
 */
public class Teleport implements Command {
    @Override
    public void act(Interpreter.Context context, Collection<String> args) throws CommandException {
        try {
            if (args.size() != 2) throw new CommandException("wrong number of arguments: " +
                                                             args.size() +
                                                             "; using: TELEPORT <x> <y>");
            Iterator<String> iterator = args.iterator();
            int x = Integer.parseInt(iterator.next());
            int y = Integer.parseInt(iterator.next());
            Model model = context.getModel();
            if (model == null) throw new CommandException("model isn't initialized");
            model.setColon(x);
            model.setRow(y);
            context.updateAll();
        } catch (Throwable e) {
            if (e.getClass().equals(CommandException.class)) {
                throw e;
            } else {
                throw new CommandException(e);
            }
        }
    }
}
