package stackCalc.operator;

import stackCalc.Calc.Context;
import java.lang.String;
import java.util.*;


public class Print implements Operator {
    public String action(Context context, String args[]) throws OperatorException {
        try {
            return context.operands.peek().toString();
        }
        catch (EmptyStackException ex) {
            throw new OperatorException("Stack is empty");
        }
    }
}
