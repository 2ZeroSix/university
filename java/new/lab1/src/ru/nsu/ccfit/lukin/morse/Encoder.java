package ru.nsu.ccfit.lukin.morse;

import java.io.*;

public class Encoder implements Handler {
    @Override
    public void handle(String args[]) throws HandlerException {
        if (args.length == 1) {
            try(InputStream inStream = new FileInputStream(args[0]);
                Reader reader = new InputStreamReader(inStream)) {
                while (reader.ready()) {
                    int symbol = reader.read();
                    if (Character.isWhitespace(symbol) &&
                            !(symbol == '\n')) {
                        System.out.print("    ");
                        symbol = reader.read();
                        while (Character.isWhitespace(symbol)) {
                            if (symbol == '\n') {
                                break;
                            } else {
                                System.out.print("       ");
                            }
                            symbol = reader.read();
                        }
                        if (symbol == -1) break;
                    }
                    String morse = Parser.getMorseBySymbol(symbol);
                    if (morse == null) {
                        throw new HandlerException("Unknown symbol: '" + String.valueOf(Character.toChars(symbol)) + "'");
                    }
                        System.out.print(morse + "   ");
                }
                System.out.println("");
            } catch (IOException e) {
                throw new HandlerException("Can't read from file: "
                                            + args[0], e);
            }
        } else {
            throw new HandlerException("Wrong number of arguments, must be 1:"
                                        + args.length);
        }
    }
}
