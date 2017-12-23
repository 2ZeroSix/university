package md5.client;


public class NotContinueException extends Throwable {
    private String errorMessage;

    NotContinueException(String errorMessage){
        this.errorMessage = errorMessage;
    }

    public String getErrorMessage() {
        return errorMessage;
    }
}
