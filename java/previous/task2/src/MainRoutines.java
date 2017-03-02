import java.lang.String;
import stackCalc.*;
import java.io.*;

import ch.qos.logback.classic.Level;
import ch.qos.logback.classic.Logger;
import org.slf4j.LoggerFactory;


public class MainRoutines {
    public static void main(String args[]) throws IOException{
        Calc calc;
        Logger logger = (Logger)LoggerFactory.getLogger("");
        logger.setLevel(Level.TRACE);
        if (args.length == 1) {
            try (InputStream stream = new FileInputStream(args[0])) {
                calc = new Calc(stream);
                calc.calculate();
            }
        } else if (args.length == 2) {
            try (InputStream is = new FileInputStream(args[0]);
                 OutputStream os = new FileOutputStream(args[1])) {
                calc = new Calc(is, os);
                calc.calculate();
            }
        }
        else {
            calc = new Calc();
            calc.calculate();
        }
    }
}
