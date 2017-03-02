package morze;

import java.io.*;
import java.util.Map;
/**
 * Created by dzs on 01.03.17.
 */
public class Parser {
    public static class InitializationFault extends Exception{
        public InitializationFault(String s) {
            super(s);
        }
    }

    private Map<String, StreamHandler> handlers;
    private Map<String, String>
    private void init(Reader initReader) throws InitializationFault, IOException {
        StringBuilder builder = new StringBuilder();
        while (initReader.ready()) {
            char c = (char) initReader.read();
            if (c != '\n') {
                builder.append(c);
                continue;
            }
            String wordCode[] = builder.toString().split("[\\h\\s\\v]");
            if (wordCode.length != 2) {

            } else if (!wordCode[1].matches("[.-]+")) {
                throw new InitializationFault("wrong morze code : " + wordCode[1]);
            }

        }
    }
    public Parser(Reader initReader) throws InitializationFault, IOException {
        init(initReader);
    }
    public Parser(InputStream initStream) throws InitializationFault, IOException {
        try(Reader reader = new InputStreamReader(initStream)) {
            init(reader);
        }
    }
    public Parser(String initFile) throws InitializationFault, IOException {
        try(InputStream initStream = new FileInputStream(initFile)) {
            try(Reader reader = new InputStreamReader(initStream)) {
                init(reader);
            }
        }
    }
    public void parse(Reader reader, Writer write) {
        try {
            StringBuilder builder = new StringBuilder();
            while (reader.ready()) {
                char c = (char)reader.read();
                if (c != '\n') {
                    builder.append(c);
                    continue;
                }
                String hadlerString[] = builder.toString().split("[\\h\\s\\v]+");
                String handlerName;

                builder = new StringBuilder();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void parse(InputStream instream, OutputStream outstream) {
        try(Reader reader = new InputStreamReader(instream)) {
            try(Writer writer = new OutputStreamWriter(outstream)) {
                parse(reader, writer);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        parse();
    }

    public void parse(InputStream instream) {
        parse(instream, System.out);
    }

    public void parse(String inFile, String outFile) {
        try(InputStream instream = new FileInputStream(inFile)){
            try(OutputStream outstream = new FileOutputStream(outFile)) {
                parse(instream, outstream);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void parse(String inFile) {
        try(InputStream instream = new FileInputStream(inFile)){
            parse(instream);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void parse() {
        parse(System.in);
    }
}
