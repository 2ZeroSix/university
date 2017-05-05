package ru.nsu.ccfit.lukin.logoWorld.commands;

import org.w3c.dom.Document;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.NodeList;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import java.io.InputStream;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

/**
 * @author Bogdan Lukin
 * factory of commands
 * to add new command add its description to ru.nsu.ccfit.lukin.logoWorld.commandFactoryConfig.xml
 * in the folowing format (case sensitive):
 *      <Command name="command name" class="full class name"/>
 * all commands must impement interface ru.nsu.ccfit.lukin.logoWorld.commands.Command
 */
public class CommandFactory {
    private static Map<String, Class<Command>> commands;

    /**
     * Error to signalize fault in static initialization in command factory
     */
    public static class initFault extends Error {
        public initFault() {}
        public initFault(String var1) {
            super(var1);
        }
        public initFault(String var1, Throwable var2) {
            super(var1, var2);
        }
        public initFault(Throwable var1) {
            super(var1);
        }
        protected initFault(String var1, Throwable var2, boolean var3, boolean var4) {
            super(var1, var2, var3, var4);
        }
    }
    static {
        try {
            commands = new HashMap<>();
            InputStream handlerConfig = CommandFactory.class.getResourceAsStream("commandFactoryConfig.xml");
            DocumentBuilder docBuilder = DocumentBuilderFactory.newInstance().newDocumentBuilder();
            {
                Document handlerConfDoc = docBuilder.parse(handlerConfig);
                NodeList handlers = handlerConfDoc.getElementsByTagName("Command");
                for (int i = 0; i < handlers.getLength(); ++i) {
                    NamedNodeMap attr = handlers.item(i).getAttributes();
                    String className = attr.getNamedItem("class").getNodeValue();
                    String commandName = attr.getNamedItem("name").getNodeValue();
                    Class commandClass = Class.forName(className);
                    if (Command.class.isAssignableFrom(commandClass)) {
                        commands.put(commandName, commandClass);
                    } else {
                        throw new initFault(Command.class.getName() + " isn't assignable by " + className);
                    }
                }
            }
        } catch(Throwable e) {
            throw new initFault(e);
        }
    }

    /**
     * @return collection of string representations of commands
     */
    static public Collection<String> getPossibleCommands() {
        return commands.keySet();
    }

    /**
     * @param commandName name of command
     * @return object of command with the specified name
     * @throws CommandException on errors with command
     */
    public Command getCommand(String commandName) throws CommandException {
        Class<Command> commandClass = commands.getOrDefault(commandName, null);
        if (commandClass == null) throw new CommandException("Unknown command name: '" + commandName + "'");
        try {
            return commandClass.newInstance();
        } catch (Exception e) {
            throw new CommandException("can't get command instance: '" + commandClass.getName() + "'", e);
        }
    }
}
