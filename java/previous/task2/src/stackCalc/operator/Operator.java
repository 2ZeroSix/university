package stackCalc.operator;

import stackCalc.Calc.Context;
import java.lang.String;


public interface Operator {
    public String action(Context context, String args[]) throws OperatorException;
}
