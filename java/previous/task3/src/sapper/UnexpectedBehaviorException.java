package sapper;

/**
 * Created by dzs on 14.02.17.
 */
public class UnexpectedBehaviorException extends RuntimeException {
    public UnexpectedBehaviorException(){
        super();
    }
    public UnexpectedBehaviorException(String message) {
        super(message);
    }
    public UnexpectedBehaviorException(String message, Throwable cause) {
        super(message, cause);
    }
    public UnexpectedBehaviorException(Throwable cause) {
        super(cause);
    }
}
