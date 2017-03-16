package ru.nsu.ccfit.lukin.morse;

import java.io.*;

public class Decoder implements Handler{
    @Override
    public void handle(String args[]) throws HandlerException{
        if (args.length == 1) {
            try (InputStream inStream = new FileInputStream(args[0]);
                 Reader reader = new InputStreamReader(inStream)) {
                StringBuilder builder = new StringBuilder();
                int spaceCount = 0;
                while (reader.ready()) {
                    int c = reader.read();
                    if (Character.isWhitespace(c)) {
                        ++spaceCount;
                        if (spaceCount == 3) {
                            String morse = builder.toString();
                            String symbol = Parser.getSymbolByMorse(morse);
                            if (symbol == null) {
                                throw new HandlerException("Unknown morse code: '" + morse + "'");
                            }
                            System.out.print(symbol);
                            builder = new StringBuilder();
                        } else if (spaceCount % 7 == 0) {
                            System.out.print(" ");
                        }
                        continue;
                    } else if (Character.getType(c) == Character.DASH_PUNCTUATION) {
                        builder.append('-');
                    } else if (c == '.') {
                        builder.append('.');
                    } else {
                        throw new HandlerException("Unsupported symbol: " + c);
                    }
                    spaceCount = 0;
                }
                String morse = builder.toString();
                String symbol = Parser.getSymbolByMorse(morse);
                if (symbol == null) {
                    throw new HandlerException("Unknown morse code: '" + morse + "'");
                }
                System.out.println(symbol);
            } catch (IOException e) {
                throw new HandlerException("Can't read from " + args[0], e);
            }
        } else {
            throw new HandlerException("Wrong number of arguments, must be 1:"
                    + args.length);
        }
    }
}
