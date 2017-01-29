package stackCalc.operator;

public class ConfigurationError extends Error {
    public ConfigurationError(){
        super();
    }
    public ConfigurationError(String message) {
        super(message);
    }
    public ConfigurationError(String message, Throwable cause) {
        super(message, cause);
    }
    public ConfigurationError(Throwable cause) {
        super(cause);
    }
}
