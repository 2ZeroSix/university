package stackCalc;

import stackCalc.operator.*;
import java.io.*;
import java.util.*;
import java.lang.*;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;


public class Calc {
    private Context context;
    private InputStream reader;
    private PrintStream writer;
    private String currentStrs[];
    private static Logger logger;
    static {
        logger = LoggerFactory.getLogger("stackCalc.Calc");
    }
    public class Context {
        public Map<String, Double> definitions;
        public Stack<Double> operands;
        private Context(){
            definitions = new HashMap<String, Double>();
            operands = new Stack<Double>();
        }
    }

    public void init(InputStream inFile, OutputStream outFile) {
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
                logger.error("Unknown operator: \"{}\"", operatorStr);
                writer.println("Unknown operator: \""+operatorStr+"\"");
            }
            catch (ReflectiveOperationException ex) {
                logger.error("Can't instantiate operator {} class", operatorStr);
                writer.println("Can't instantiate operator "+operatorStr+" class");
            }
            catch (OperatorException ex) {
                logger.error("Exception caused in \"{}\":\n\t{}",operatorStr, ex);
                writer.println("Exception caused in \""+operatorStr+"\":\n\t"+ex);
            }
        }
        logger.trace("calculating completed");
    }

    private String getOperatorStr() {
        logger.trace("getting operator string");
        try {
            StringBuilder strbld = new StringBuilder();
            int c;
            if ((c = reader.read()) == '#') {
                while ((c = reader.read()) != -1) {
                    if (c == '\n') {
                        break;
                    }
                }                
            }
            else if (c != -1 && c != '\n') {
                strbld.append((char)c);
            }
            while ((c = reader.read()) != -1) {
                if (c == '\n') {
                    break;
                }
                strbld.append((char)c);
            }
            if(strbld.length() == 0) {
                if (c == -1) {
                    return null;
                } else {
                    return getOperatorStr();
                }
            }
            currentStrs = strbld.toString().split("[\\h\\s\\v]+");
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
