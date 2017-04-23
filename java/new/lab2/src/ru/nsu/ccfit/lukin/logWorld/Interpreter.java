package ru.nsu.ccfit.lukin.logWorld;

import ru.nsu.ccfit.lukin.logWorld.commands.Command;
import ru.nsu.ccfit.lukin.logWorld.commands.CommandException;
import ru.nsu.ccfit.lukin.logWorld.commands.CommandFactory;
import java.io.*;
import java.util.ArrayList;

/**
 * Created by dzs on 22.03.17.
 */
public class Interpreter implements Runnable {
    private static CommandFactory factory = new CommandFactory();
    private Model model;
    private InputStream ins;
    private OutputStream ous;

    public class Context {
        public Model getModel() {
            return Interpreter.this.model;
        }
        public void setModel(Model model) {
            Interpreter.this.model = model;
        }

        public synchronized void updateAll() {
            int rows = model.getRows();
            int colons = model.getColons();

            PrintWriter prw = new PrintWriter(ous);
            for (int row = 0; row < rows; ++row) {
                prw.print("|");
                for (int colon = 0; colon < colons; ++colon) {
                    prw.print(model.getPoint(row, colon) + "|");
                }
                prw.println();
            }
            prw.flush();
        }
    }

    public Interpreter() {
        ins = System.in;
        ous = System.out;
    }
    @Override
    public void run() {
        try (Reader reader = new InputStreamReader(ins)) {
            int ch;
            StringBuilder builder = new StringBuilder();
            String commandName = null;
            Command command;
            ArrayList<String> args = new ArrayList<>(5);
            Context context = new Context();

            while((ch = reader.read()) != -1) {
                if (Character.isWhitespace(ch)) {
                    if (builder.length() > 0) {
                        if (commandName == null)    commandName = builder.toString();
                        else                        args.add(builder.toString());
                        builder.delete(0, builder.length());
                    }
                } else builder.append((char)ch);
                if (ch == '\n') {
                    if (commandName != null && commandName.length() > 0) {
                        try {
                            command = factory.getCommand(commandName);
                            command.act(context, args);
                        } catch (CommandException e) {
                            System.err.println(e.getLocalizedMessage());
                        }
                    }
                    commandName = null;
                    args.clear();
                }
            }
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }
}
