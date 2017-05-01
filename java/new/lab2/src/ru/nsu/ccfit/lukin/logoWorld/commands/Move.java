package ru.nsu.ccfit.lukin.logoWorld.commands;

import ru.nsu.ccfit.lukin.logoWorld.Interpreter;
import ru.nsu.ccfit.lukin.logoWorld.Model;

import java.util.Collection;
import java.util.Iterator;

/**
 * Created by dzs on 22.03.17.
 */
public class Move implements Command {
    @Override
    public void act(Interpreter.Context context, Collection<String> args) throws CommandException {
        try {
            if (args.size() != 2) throw new CommandException("wrong number of arguments: " +
                                                             args.size() +
                                                             "; using: b. MOVE [L|R|U|D] <steps>");
            Iterator<String> iterator = args.iterator();
            String direction    = iterator.next();
            int steps           = Integer.parseInt(iterator.next());
            Model model = context.getModel();
            if (model == null) throw new CommandException("model isn't initialized");
            int colon   = model.getCurrentColon();
            int colons  = model.getColons();
            int row     = model.getCurrentRow();
            int rows    = model.getRows();
            switch (direction) {
                case "L":
                    model.setCurrentColon((colon - steps % colons + colons) % colons);
                    if (model.isDrawable()) {
                        for (int i = colon; i >= colon - steps && i >= 0; --i)
                            model.shadePoint(row, i);
                        if (colon - steps < 0)
                            for (int i = colons - 1; i >= colon - steps + colons && i >= 0; --i)
                                model.shadePoint(row, i);
                    }
                    break;
                case "R":
                    model.setCurrentColon((colon + steps) % colons);
                    if (model.isDrawable()) {
                        for (int i = colon; i <= colon + steps && i < colons; ++i)
                            model.shadePoint(row, i);
                        if (colon + steps >= colons)
                            for (int i = 0; i <= (colon + steps) % colons; ++i)
                                model.shadePoint(row, i);
                    }
                    break;
                case "U":
                    model.setCurrentRow((row - steps % rows + rows) % rows);
                    if (model.isDrawable()) {
                        for (int i = row; i >= row - steps && i >= 0; --i)
                            model.shadePoint(i, colon);
                        if (row - steps < 0)
                            for (int i = rows - 1; i >= row - steps + rows && i >= 0; --i)
                                model.shadePoint(i, colon);
                    }
                    break;
                case "D":
                    model.setCurrentRow((row + steps) % rows);
                    if (model.isDrawable()) {
                        for (int i = row; i <= row + steps && i < rows; ++i)
                            model.shadePoint(i, colon);
                        if (row + steps >= rows)
                            for (int i = 0; i <= (row + steps) % rows; ++i)
                                model.shadePoint(i, colon);
                    }
                    break;
                default:
                    throw new CommandException("wrong direction: '" + direction + "'");
            }
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
