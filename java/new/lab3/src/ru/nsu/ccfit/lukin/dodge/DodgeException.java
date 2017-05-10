package ru.nsu.ccfit.lukin.dodge;

/**
 * Created by dzs on 09.05.17.
 */
public class DodgeException extends Exception {
    public DodgeException() {
    }

    public DodgeException(String var1) {
        super(var1);
    }

    public DodgeException(String var1, Throwable var2) {
        super(var1, var2);
    }

    public DodgeException(Throwable var1) {
        super(var1);
    }

    protected DodgeException(String var1, Throwable var2, boolean var3, boolean var4) {
        super(var1, var2, var3, var4);
    }
}
