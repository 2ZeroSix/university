package ru.nsu.ccfit.lukin.Chat.courier;

/**
 * Created by йцук on 15.06.2017.
 */
public class CourierException extends Exception {
    public CourierException() {
    }

    public CourierException(String message) {
        super(message);
    }

    public CourierException(String message, Throwable cause) {
        super(message, cause);
    }

    public CourierException(Throwable cause) {
        super(cause);
    }

    protected CourierException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
        super(message, cause, enableSuppression, writableStackTrace);
    }
}
