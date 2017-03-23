package ru.nsu.ccfit.lukin.logWorld;

import com.googlecode.lanterna.TerminalFacade;
import com.googlecode.lanterna.input.Key;
import com.googlecode.lanterna.screen.Screen;
import com.googlecode.lanterna.terminal.Terminal;
import ru.nsu.ccfit.lukin.logWorld.commands.Command;
import ru.nsu.ccfit.lukin.logWorld.commands.CommandException;
import ru.nsu.ccfit.lukin.logWorld.commands.CommandFactory;
import java.io.*;
import java.nio.charset.Charset;
import java.util.ArrayList;

/**
 * Created by dzs on 22.03.17.
 */
public class Interpreter implements Runnable {
    private static CommandFactory factory = new CommandFactory();
    private Model model;
    private Screen screen;
    public class Context {
        public Model getModel() {
            return Interpreter.this.model;
        }
        public void setModel(Model model) {
            Interpreter.this.model = model;
        }
        public synchronized void updateAt(int row, int colon, boolean refresh) {
            switch (model.getPoint(row, colon)) {
                case EMPTY:
                    screen.putString(colon, row, " ",
                                        Terminal.Color.BLUE, Terminal.Color.BLUE);
                    break;
                case SHADED:
                    screen.putString(colon, row, " ",
                                        Terminal.Color.BLACK, Terminal.Color.BLACK);
                    break;
                case CURRENT:
                    screen.putString(colon, row, " ",
                            Terminal.Color.RED, Terminal.Color.RED);
                    break;
            }
            if (refresh) screen.refresh();
            screen.setCursorPosition(0, model.getRows());
        }

        public synchronized void updateAt(int row, int colon) {
            updateAt(row, colon, true);
        }
        public synchronized void updateAll() {
            int rows = model.getRows();
            int colons = model.getColons();
            screen.clear();
            for (int row = 0; row < rows; ++row) {
                for (int colon = 0; colon < colons; ++colon) {
                    updateAt(row, colon, false);
                }
            }
            screen.completeRefresh();
        }
    }
    public Interpreter() {
        screen = new Screen(TerminalFacade.createTextTerminal(System.in, System.out, Charset.forName("UTF-8")));
        screen.clear();
    }
    @Override
    public void run() {
        screen.startScreen();
        try (Reader reader = new InputStreamReader(System.in)) {
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
        finally {
            screen.stopScreen();
        }
    }
}
