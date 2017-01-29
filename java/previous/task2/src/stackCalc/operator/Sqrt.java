package stackCalc.operator;

import stackCalc.Calc.Context;
import java.lang.*;
import java.util.*;


public class Sqrt implements Operator {
    public String action(Context context, String args[]) throws OperatorException {
        double arg;
        try {
            arg = context.operands.pop();
        }
        catch (EmptyStackException ex) {
            throw new OperatorException("Stack is empty");
        }
        context.operands.push(Math.sqrt(arg));
        return null;
    }
}
