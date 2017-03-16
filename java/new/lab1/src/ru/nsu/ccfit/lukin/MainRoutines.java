package ru.nsu.ccfit.lukin;

import ru.nsu.ccfit.lukin.morse.Parser;
import java.io.*;

public class MainRoutines {
    public static void main(String args[]) throws IOException {
        try {
            InputStream inStream = null;
            switch (args.length) {
                case 0: inStream = System.in; break;
                case 1: inStream = new FileInputStream(args[0]); break;
            }
            Parser parser = new Parser(inStream);
            parser.run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
