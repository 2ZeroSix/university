package stackCalc;

import java.io.*;
import java.util.*;
import java.lang.*;


public class Calc {
    public class Context {
        public Map<String, Double> definitions;
        public Stack<Double> operands;
    }
    private Context context;
    private BufferedReader reader;
    private Writer writer;
    private String currentStrs[];

    public void init(InputStream inFile, OutputStream outFile) {
        reader = new BufferedReader(new InputStreamReader(inFile));
        writer = new OutputStreamWriter(outFile);        
    }
    public Calc(InputStream inFile, OutputStream outFile) {init(inFile, outFile);}
    public Calc(InputStream inFile)                    {init(inFile, System.out);}
    public Calc()                                   {init(System.in, System.out);}

    public void calculate() {
        String operatorStr;
        while((operatorStr = getOperatorStr()) != null) {
            String args[] = getArguments();
            Operator operator = OperatorFactory.getOperator(operatorStr);
            operator.action(context, args);
        }
    }

    private String getOperatorStr() {
        try {
            if (reader.ready()) {
                currentStrs = reader.readLine().split("[\\W]*");
                return currentStrs[0];
            }
            else {
                return null;
            }
        }
        finally {
            return null;
        }
    }

    private String[] getArguments() {
        String strs[] = new String[currentStrs.length - 1];
        System.arraycopy(currentStrs, 1, strs, 0, strs.length);
        return strs;
    }
}
