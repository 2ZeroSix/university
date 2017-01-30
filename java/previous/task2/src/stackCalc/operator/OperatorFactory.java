package stackCalc.operator;

import java.util.*;
import java.lang.*;
import java.io.*;


public final class OperatorFactory {

    private static Map<String, Class<Operator>> opClasses;

    static {
        opClasses = new HashMap<String, Class<Operator>>();
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(OperatorFactory.class.getResourceAsStream("OperatorFactoryConfig")))) {
            if (reader != null) {
                while(reader.ready()) {
                    String strs[] = reader.readLine().split("[\\h\\s\\v]+");
                    if (strs.length != 2) {
                        throw new ConfigurationError("Wrong number of words in line");
                    }
                    opClasses.put(strs[0], (Class<Operator>)Class.forName(strs[1]));
                }
            }
        }
        catch (IOException ex) {
            throw new ConfigurationError("Can't read config file", ex);
        }
        catch (ClassNotFoundException ex) {
            throw new ConfigurationError("Can't find class listed in config file", ex);
        }
    }

    private OperatorFactory() {};

    public static Operator getOperator(String operatorStr) throws ClassNotFoundException, InstantiationException, IllegalAccessException {
        Operator op = null;
        if (opClasses.containsKey(operatorStr)) {
            op = opClasses.get(operatorStr).newInstance();
        } else {
            throw new ClassNotFoundException("Can't find in config: " + operatorStr);
        }
        return op;
    }
}
