package stackCalc.operator;

import stackCalc.Calc.Context;
import java.lang.String;
import java.util.*;


public class Pop implements Operator {
    public String action(Context context, String args[]) throws OperatorException {
        try {
            context.operands.pop();
        }
        catch (EmptyStackException ex) {
            throw new OperatorException("Stack is empty");
        }
        return null;
    }
}
