package ru.nsu.ccfit.lukin.logoWorld.commands;

/**
 * Exception to signalize problems related to commands
 */
public class CommandException extends Exception {
    public CommandException() {
    }

    public CommandException(String var1) {
        super(var1);
    }

    public CommandException(String var1, Throwable var2) {
        super(var1, var2);
    }

    public CommandException(Throwable var1) {
        super(var1);
    }

    protected CommandException(String var1, Throwable var2, boolean var3, boolean var4) {
        super(var1, var2, var3, var4);
    }

}
