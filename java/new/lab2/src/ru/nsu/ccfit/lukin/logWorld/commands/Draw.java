package ru.nsu.ccfit.lukin.logWorld.commands;

import ru.nsu.ccfit.lukin.logWorld.Interpreter;
import ru.nsu.ccfit.lukin.logWorld.Model;

import java.util.Collection;

/**
 * Created by dzs on 22.03.17.
 */
public class Draw implements Command {
    @Override
    public void act(Interpreter.Context context, Collection<String> args) throws CommandException {
        try {
            if (args.size() != 0) throw new CommandException("wrong number of arguments: " +
                                                             args.size() +
                                                             "; using: DRAW");
            Model model = context.getModel();
            if (model == null) throw new CommandException("model isn't initialized");
            model.setDrawable(true);
            model.setPoint(model.getRow(), model.getColon(), Model.Point.SHADED);
            context.updateAt(model.getRow(), model.getColon());
        } catch (Throwable e) {
            if (e.getClass().equals(CommandException.class)) {
                throw e;
            } else {
                throw new CommandException(e);
            }
        }
    }
}
