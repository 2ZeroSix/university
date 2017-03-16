package ru.nsu.ccfit.lukin.morse;

public class HandlerException extends Exception{
    public HandlerException() {
    }

    public HandlerException(String var1) {
        super(var1);
    }

    public HandlerException(String var1, Throwable var2) {
        super(var1, var2);
    }

    public HandlerException(Throwable var1) {
        super(var1);
    }

    protected HandlerException(String var1, Throwable var2, boolean var3, boolean var4) {
        super(var1, var2, var3, var4);
    }
}
