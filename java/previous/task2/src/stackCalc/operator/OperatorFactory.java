package stackCalc.operator;

import java.util.*;
import java.lang.*;
import java.io.*;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public final class OperatorFactory {

    private static Map<String, Class<Operator>> opClasses;
    private static Logger logger; 
    static {
        logger = LoggerFactory.getLogger("stackCalc.operator.OperatorFactory");
        logger.trace("initializing OperatorFactory");
        opClasses = new HashMap<>();
        try (BufferedReader reader =new BufferedReader(
                                    new InputStreamReader(
                                    OperatorFactory.class
                                    .getResourceAsStream("OperatorFactoryConfig")))) {
            while(reader.ready()) {
                String strParams[] = reader.readLine().split("[\\h\\s\\v]+");
                if (strParams.length != 2) {
                    throw new ConfigurationError("Wrong number of words in line");
                }
                opClasses.put(strParams[0], (Class<Operator>)Class.forName(strParams[1]));
            }
        }
        catch (IOException ex) {
            logger.error("Exception catched while initializing OperatorFactory: {}", ex.toString());
            throw new ConfigurationError("Can't read config file", ex);
        }
        catch (ClassNotFoundException ex) {
            logger.error("Exception catched while initializing OperatorFactory: {}", ex.toString());
            throw new ConfigurationError("Can't find class listed in config file", ex);
        }
        logger.trace("initializing OperatorFactory completed");
    }

    private OperatorFactory() {}

    public static Operator getOperator(String operatorStr) throws ClassNotFoundException, InstantiationException, IllegalAccessException {
        Operator op;
        logger.trace("getting operator");
        if (opClasses.containsKey(operatorStr)) {
            op = opClasses.get(operatorStr).newInstance();
        } else {
            logger.error("getting operator incomplete");
            throw new ClassNotFoundException("Can't find in config: " + operatorStr);
        }
        logger.trace("getting operator completed");
        return op;
    }
}
