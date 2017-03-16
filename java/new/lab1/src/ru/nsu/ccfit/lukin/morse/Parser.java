package ru.nsu.ccfit.lukin.morse;

import org.w3c.dom.Document;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.NodeList;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import java.io.*;
import java.util.HashMap;
import java.util.Map;

public class Parser {
    private static Map<String, Handler> handlers;
    private static Map<String, Integer> morseToSymbol;
    private static Map<Integer, String> symbolToMorse;

    public static String getSymbolByMorse(String morse) {
        return morseToSymbol.containsKey(morse)
                ? String.valueOf(Character.toChars(
                        morseToSymbol.get(morse)))
                : null;
    }

    public static String getMorseBySymbol(int symbol) {
        return symbolToMorse.get(symbol);
    }

    private InputStream inStream;
    static {
        handlers = new HashMap<>();
        morseToSymbol = new HashMap<>();
        symbolToMorse = new HashMap<>();
        try {
            InputStream handlerConfig = Parser.class.getResourceAsStream("ParserConfig.xml");
            InputStream morseConfig = new FileInputStream("morseConfig.xml");
            DocumentBuilder docBuilder = DocumentBuilderFactory.newInstance().newDocumentBuilder();
            {
                Document handlerConfDoc = docBuilder.parse(handlerConfig);
                NodeList handlers = handlerConfDoc.getElementsByTagName("Handler");
                for (int i = 0; i < handlers.getLength(); ++i) {
                    NamedNodeMap attr = handlers.item(i).getAttributes();
                    Handler handler = (Handler)Class.forName(attr.getNamedItem("class").
                                                             getNodeValue()).newInstance();
                    Parser.handlers.put(attr.getNamedItem("name").getNodeValue(), handler);
                }
            }
            {
                Document morseConfDoc = docBuilder.parse(morseConfig);
                NodeList morseSymbols = morseConfDoc.getElementsByTagName("ms");
                for (int i = 0; i < morseSymbols.getLength(); ++i) {
                    NamedNodeMap attr = morseSymbols.item(i).getAttributes();
                    String morse = attr.getNamedItem("m").getNodeValue();
                    String symbolStr = attr.getNamedItem("s").getNodeValue();
                    if(symbolStr.length() != 1) {
                        throw  new InitializationFault("symbol must be a single Unicode character");
                    }
                    int symbol = symbolStr.codePointAt(0);
                    if (!morseToSymbol.containsKey(morse) &&
                            !symbolToMorse.containsKey(symbol)) {
                        morseToSymbol.put(morse, symbol);
                        symbolToMorse.put(symbol, morse);
                    }
                    else {
                        throw new InitializationFault("symbol: '" + symbolStr + "' and morse code: '"
                                                            + morse + "' already in table" );
                    }
                }
            }
        } catch (Throwable e) {
            throw new InitializationFault(e);
        }
    }

    public static class InitializationFault extends Error {
        public InitializationFault() {
        }

        public InitializationFault(String var1) {
            super(var1);
        }

        public InitializationFault(String var1, Throwable var2) {
            super(var1, var2);
        }

        public InitializationFault(Throwable var1) {
            super(var1);
        }


    }

    public Parser(InputStream inStream) {
        this.inStream = inStream;
    }

    public void run() {
        try {
            StringBuilder builder = new StringBuilder();
            int c;
            while ((c = inStream.read()) != -1) {
                if (c != '\n') {
                    builder.append((char)c);
                    continue;
                }
                String handlerString[] = builder.toString().split("[\\h\\s\\v]+");
                if (handlerString.length >= 1 && handlerString[0].length() > 0) {
                    String handlerName = handlerString[0];
                    String handlerArgs[] = new String[handlerString.length - 1];
                    System.arraycopy(handlerString, 1, handlerArgs, 0 , handlerArgs.length);
                    Handler handler = handlers.get(handlerName);
                    if (handler == null) {
                        System.err.println("Can't find handler with name: " + handlerName);
                    } else {
                        try {
                            handler.handle(handlerArgs);
                        } catch (HandlerException e) {
                            e.printStackTrace();
                        }
                    }
                }
                builder = new StringBuilder();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
