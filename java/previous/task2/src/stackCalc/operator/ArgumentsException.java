package stackCalc.operator;

public class ArgumentsException extends OperatorException {
    public ArgumentsException(){
        super();
    }
    public ArgumentsException(String message) {
        super(message);
    }
    public ArgumentsException(String message, Throwable cause) {
        super(message, cause);
    }
    public ArgumentsException(Throwable cause) {
        super(cause);
    }
}