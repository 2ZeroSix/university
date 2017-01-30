package stackCalc;

import stackCalc.operator.*;
import java.io.*;
import java.util.*;
import java.lang.*;


public class Calc {
    public class Context {
        public Map<String, Double> definitions;
        public Stack<Double> operands;
        private Context(){
            definitions = new HashMap<String, Double>();
            operands = new Stack<Double>();
        }
    }
    private Context context;
    private InputStream reader;
    private PrintStream writer;
    private String currentStrs[];

    public void init(InputStream inFile, OutputStream outFile) {
        reader = inFile;
        writer = new PrintStream(outFile, true);
        context = new Context();
    }
    public Calc(InputStream inFile, OutputStream outFile) {init(inFile, outFile);}
    public Calc(InputStream inFile)                    {init(inFile, System.out);}
    public Calc(OutputStream outFile)                  {init(System.in, outFile);}
    public Calc()                                   {init(System.in, System.out);}

    public void calculate() {
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
                writer.println("Unknown operator: \"" + operatorStr + "\"");
            }
            catch (ReflectiveOperationException ex) {
                writer.println("Can't instantiate operator " + operatorStr + " class");
            }
            catch (OperatorException ex) {
                writer.println("Exception caused in \"" + operatorStr + "\":\n\t" + ex);
            }
        }
    }

    private String getOperatorStr() {
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
            return currentStrs[0];
        } catch(IOException ex) {
            return null;
        }
    }

    private String[] getArguments() {
        String strs[] = new String[currentStrs.length - 1];
        System.arraycopy(currentStrs, 1, strs, 0, strs.length);
        return strs;
    }
}
