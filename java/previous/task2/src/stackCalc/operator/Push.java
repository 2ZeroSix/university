package stackCalc.operator;

import stackCalc.Calc.Context;
import java.lang.String;
import java.util.*;


public class Push implements Operator {
    public String action(Context context, String args[]) throws OperatorException {
        if (args.length == 1) {
            double arg;
            if (context.definitions.containsKey(args[0])) {
                arg = context.definitions.get(args[0]);
            }
            else {
                try {
                    arg = Double.parseDouble(args[0]);
                }
                catch(NumberFormatException ex) {
                    throw new ArgumentsException("Wrong format of argument");
                }
            }
            context.operands.push(arg);
        }
        else {
            throw new ArgumentsException("Push needs 1 argument");
        }
        return null;
    }
}
