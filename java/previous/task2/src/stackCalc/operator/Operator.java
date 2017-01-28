package stackCalc.operator;

import stackCalc.Calc.Context;
import java.lang.String;


public abstract class Operator {
    public abstract String action(Context context, String args[]);
}
