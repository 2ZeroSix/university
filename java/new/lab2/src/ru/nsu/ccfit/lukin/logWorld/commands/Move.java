package ru.nsu.ccfit.lukin.logWorld.commands;

import ru.nsu.ccfit.lukin.logWorld.Interpreter;
import ru.nsu.ccfit.lukin.logWorld.Model;

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
            int colon   = model.getColon();
            int colons  = model.getColons();
            int row     = model.getRow();
            int rows    = model.getRows();
            switch (direction) {
                case "L":
                    model.setColon((colon - steps % colons + colons) % colons);
                    for (int i = colon; i >= colon - steps  && i >= 0; --i)
                        model.setPoint(row, i, Model.Point.SHADED);
                    if (colon - steps < 0)
                        for (int i = colons - 1; i > colon - steps + colons - 1 && i >= 0; --i)
                            model.setPoint(row, i, Model.Point.SHADED);
                    break;
                case "R":
                    model.setColon((colon + steps) % colons);
                    for (int i = colon; i <= colon + steps && i < colons; ++i)
                        model.setPoint(row, i, Model.Point.SHADED);
                    if (colon + steps >= colons)
                        for (int i = 0; i <= (colon + steps) % colons; ++i)
                            model.setPoint(row, i, Model.Point.SHADED);
                    break;
                case "U":
                    model.setRow((row - steps % rows + rows) % rows);
                    for (int i = row; i >= row - steps  && i >= 0; --i)
                        model.setPoint(i, colon, Model.Point.SHADED);
                    if (row - steps < 0)
                        for (int i = rows - 1; i > row - steps + rows - 1 && i >= 0; --i)
                            model.setPoint(i, colon, Model.Point.SHADED);
                    break;
                case "D":
                    model.setRow((row + steps) % rows);
                    for (int i = row; i <= row + steps && i < rows; ++i)
                        model.setPoint(i, colon, Model.Point.SHADED);
                    if (row + steps >= rows)
                        for (int i = 0; i <= (row + steps) % rows; ++i)
                            model.setPoint(i, colon, Model.Point.SHADED);
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
