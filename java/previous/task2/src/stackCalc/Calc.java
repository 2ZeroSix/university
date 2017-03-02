package stackCalc;

import stackCalc.operator.*;
import java.io.*;
import java.util.*;
import java.lang.*;
// import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import ch.qos.logback.classic.Logger;
import ch.qos.logback.classic.Level;

public class Calc {
    private Context context;
    private InputStream reader;
    private PrintStream writer;
    private String currentStrs[];
    private static Logger logger;
    static {
        logger = (Logger)LoggerFactory.getLogger("stackCalc");
        logger.setLevel(Level.TRACE);
    }
    public class Context {
        public Map<String, Double> definitions;
        public Stack<Double> operands;
        private Context(){
            definitions = new HashMap<>();
            operands = new Stack<>();
        }
    }

    private void init(InputStream inFile, OutputStream outFile) {
        reader = inFile;
        writer = new PrintStream(outFile, true);
        context = new Context();
        logger.trace("new Calc constructed");
    }
    public Calc(InputStream inFile, OutputStream outFile) {init(inFile, outFile);}
    public Calc(InputStream inFile)                    {init(inFile, System.out);}
    public Calc(OutputStream outFile)                  {init(System.in, outFile);}
    public Calc()                                   {init(System.in, System.out);}

    public void calculate() {
        logger.trace("calculating started");
        String operatorStr;
        while((operatorStr = getOperatorStr()) != null) {
            String args[] = getArguments();
            try {
                Operator operator = OperatorFactory.getOperator(operatorStr);
                String str = operator.action(context, args);
                if (str != null) {
                    writer.println(str);
                }
            }
            catch (ClassNotFoundException ex) {
                logger.warn("Unknown operator: \"{}\"", operatorStr);
            }
            catch (ReflectiveOperationException ex) {
                logger.warn("Can't instantiate operator {} class", operatorStr);
            }
            catch (OperatorException ex) {
                logger.warn("Exception caused in \"{}\":\n\t{}", operatorStr, ex.toString());
            }
        }
        logger.trace("calculating completed");
    }

    private String getOperatorStr() {
        logger.trace("getting operator string");
        try {
            while (true) {
                int c;
                StringBuilder strbld = new StringBuilder();
                while ((c = reader.read()) != -1) {
                    if (c == '\n') {
                        break;
                    }
                    strbld.append((char) c);
                }
                currentStrs = strbld.toString().split("[\\h\\s\\v]+");
                if (currentStrs.length == 0 || currentStrs[0].length() == 0 || currentStrs[0].startsWith("#")) {
                    if (c == -1) {
                        return null;
                    }
                } else {
                    break;
                }
            }
            logger.trace("getting operator string completed");
            return currentStrs[0];
        } catch(IOException ex) {
            logger.error("exception catched while getting operator string: {}", ex);
            return null;
        }
    }

    private String[] getArguments() {
        logger.trace("getting arguments of operator");
        String strs[] = new String[currentStrs.length - 1];
        System.arraycopy(currentStrs, 1, strs, 0, strs.length);
        logger.trace("getting arguments of completed");
        return strs;
    }
}
