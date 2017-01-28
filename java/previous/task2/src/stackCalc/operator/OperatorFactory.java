package stackCalc.operator;

import java.util.*;
import java.lang.*;


public final class OperatorFactory {
    private static Map<String, Class<Operator>> opClasses;

    static {
        // TODO implement
    }

    private OperatorFactory() {};

    public static Operator getOperator(String operatorStr) {
        Operator op = null;
        try {
            if (opClasses.containsKey(operatorStr)) {
                op = opClasses.get(operatorStr).newInstance();
            } else {
                throw new ClassNotFoundException("Can't find in config: " + operatorStr);
            }
        }
        catch (ReflectiveOperationException ex) {
            // TODO implement something
        }
        return op;
    }
}
