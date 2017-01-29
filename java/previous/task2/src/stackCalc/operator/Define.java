package stackCalc.operator;

import stackCalc.Calc.Context;
import java.lang.String;
import java.util.*;


public class Define implements Operator {
    public String action(Context context, String args[]) throws OperatorException {
        if (args.length == 2) {
            double arg;
            if (context.definitions.containsKey(args[1])) {
                arg = context.definitions.get(args[1]);
            }
            else {
                try {
                    arg = Double.parseDouble(args[1]);
                }
                catch(NumberFormatException ex) {
                    throw new ArgumentsException("Wrong format of argument");
                }
            }
            context.definitions.put(args[0], arg);
        }
        else {
            throw new ArgumentsException("Push needs 1 argument");
        }
        return null;
    }
}
