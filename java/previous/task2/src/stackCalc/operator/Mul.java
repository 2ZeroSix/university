package stackCalc.operator;

import stackCalc.Calc.Context;
import java.lang.String;
import java.util.*;

public class Mul implements Operator {
    public String action(Context context, String args[]) throws OperatorException{
        double arg1, arg2;
        try {
            arg2 = context.operands.pop();
        }
        catch (EmptyStackException ex) {
            throw new OperatorException("Stack is empty");
        }
        try {
            arg1 = context.operands.pop();
        }
        catch (EmptyStackException ex) {
            context.operands.push(arg2);
            throw new OperatorException("Stack is empty");
        }
        context.operands.push(arg1 * arg2);
        return null;
    }
}
