package ru.nsu.ccfit.lukin.morse;

import java.io.*;
import java.util.HashMap;
import java.util.Map;

public class Decoder implements Handler{
    @Override
    public void handle(String args[]) throws HandlerException{
        if (args.length == 1) {
            try (InputStream inStream = new FileInputStream(args[0]);
                 Reader reader = new InputStreamReader(inStream)) {
                Map<String, Long> symbolFrequency = new HashMap<>();
                StringBuilder builder = new StringBuilder();
                int spaceCount = 0;
                while (reader.ready()) {
                    int c = reader.read();
                    if (Character.isWhitespace(c)) {
                        ++spaceCount;
                        if (spaceCount == 3) {
                            if (builder.length() > 0) {
                                String morse = builder.toString();
                                String symbol = Parser.getSymbolByMorse(morse);
                                if (symbol == null) {
                                    throw new HandlerException("Unknown morse code: '" + morse + "'");
                                }
                                symbolFrequency.put(symbol, symbolFrequency.containsKey(symbol) ?
                                        symbolFrequency.get(symbol) + 1 : 1);
                                System.out.print(symbol);
                                builder = new StringBuilder();
                            }
                        } else if (spaceCount % 7 == 0) {
                            System.out.print(" ");
                        }
                        continue;
                    } else if (Character.getType(c) == Character.DASH_PUNCTUATION) {
                        builder.append('-');
                    } else if (c == '.') {
                        builder.append('.');
                    } else {
                        throw new HandlerException("Unsupported symbol: " + String.valueOf(Character.toChars(c)));
                    }
                    spaceCount = 0;
                }
                if (builder.length() > 0) {
                    String morse = builder.toString();
                    String symbol = Parser.getSymbolByMorse(morse);
                    if (symbol == null) {
                        throw new HandlerException("Unknown morse code: '" + morse + "'");
                    }
                    symbolFrequency.put(symbol, symbolFrequency.containsKey(symbol) ?
                            symbolFrequency.get(symbol) + 1 : 1);
                    System.out.println(symbol);
                } else {
                    System.out.println("");
                }
                try (PrintStream ps = new PrintStream("symbolFrequency.csv")) {
                    symbolFrequency.forEach((s, count) -> ps.println("\"" + s + "\", " + count));
                } catch (IOException e) {
                    throw new HandlerException("Can't write symbols frequency ", e);
                }
            } catch (IOException e) {
                throw new HandlerException("Can't read from " + args[0], e);
            }
        } else {
            throw new HandlerException("Wrong number of arguments, must be 1:"
                    + args.length);
        }
    }
}
