package ru.nsu.ccfit.lukin.logoWorld;

import ru.nsu.ccfit.lukin.logoWorld.commands.CommandException;
import ru.nsu.ccfit.lukin.logoWorld.commands.CommandFactory;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.Scanner;

/**
 * @author Bogdan Lukin
 * Simple Interpreter for logoworld game (controller in MVC)
 * default commands contained in package ru.nsu.ccfit.lukin.logoWorld.commands
 * to add new command see ru.nsu.ccfit.lukin.logoWorld.commands.logoWorld.commands.CommandFactory
 * using:
 *      Interpreter interpreter = new Interpreter(inputStream, outputStream);
 *      interpreter.run();
 */
public class Interpreter implements Runnable {
    private Model model;
    private InputStream ins;
    private OutputStream ous;
    private boolean runnable;
    /**
     * class for getting and changing interpreter state
     */
    public class Context {
        /**
         * @return current model of interpreter
         */
        public Model getModel() {
            return Interpreter.this.model;
        }

        /**
         * @param model model to set in the interpreter
         */
        public void setModel(Model model) {
            Interpreter.this.model = model;
        }

        /**
         * stop interpreter
         */
        public void stop() {
            Interpreter.this.runnable = false;
        }

        /**
         * update current view (view in MVC)
         */
        public synchronized void updateAll() {
            int rows = model.getRows();
            int colons = model.getColons();
            try {
                for (int row = 0; row < rows; ++row) {
                    ous.write("|".getBytes());
                    for (int colon = 0; colon < colons; ++colon) {
                        ous.write((model.getPoint(row, colon) + "|").getBytes());
                    }
                    ous.write("\n".getBytes());
                }
            } catch (IOException ignored) {
            }
        }
    }

    /**
     * init interpreter with given streams
     * @param ins input stream
     * @param ous output stream
     */
    public Interpreter (InputStream ins, OutputStream ous) {
        this.ins = ins;
        this.ous = ous;
        this.runnable = true;
    }
    /**
     * init interpreter with standard streams
     */
    public Interpreter() {
        this(System.in, System.out);
    }

    /**
     * run interpreter
     */
    @Override
    public void run() {
        CommandFactory factory = new CommandFactory();
        Scanner scanner = new Scanner(ins);
        scanner.useDelimiter("[\\v]+");
        Context context = new Context();
        while(runnable && scanner.hasNext()) {
            try {
                String[] commandStrings = scanner.next().split("[\\h\\s]+");
                factory.getCommand(commandStrings[0])
                        .act(context, Arrays
                                .asList(commandStrings)
                                .subList(1, commandStrings.length));
            } catch (CommandException e) {
                System.err.println(e.getLocalizedMessage());
            }
        }
    }
}
