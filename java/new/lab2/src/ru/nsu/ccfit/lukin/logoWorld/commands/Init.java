package ru.nsu.ccfit.lukin.logoWorld.commands;

import ru.nsu.ccfit.lukin.logoWorld.Interpreter;
import ru.nsu.ccfit.lukin.logoWorld.Model;

import java.util.Collection;
import java.util.Iterator;

/**
 * command to init logoworld
 * using: 'INIT' <width> <height> <x> <y>
 */
public class Init implements Command {
    @Override
    public void act(Interpreter.Context context, Collection<String> args) throws CommandException {
        try {
            if (args.size() != 4) throw new CommandException("wrong number of arguments: " +
                                                             args.size() +
                                                             "; using: 'INIT' <width> <height> <x> <y>");
            Iterator<String> iterator = args.iterator();
            int width   = Integer.parseInt(iterator.next());
            int height  = Integer.parseInt(iterator.next());
            int x       = Integer.parseInt(iterator.next());
            int y       = Integer.parseInt(iterator.next());
            Model model = new Model(height, width, y, x);
            context.setModel(model);
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
