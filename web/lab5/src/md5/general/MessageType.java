package md5.general;

public class MessageType {
    public static final byte FIRST_CONNECT     = (byte)0;
    public static final byte NOT_FIRST_CONNECT = (byte)1;

    public static final byte OK                = (byte)0;
    public static final byte NOT_OK            = (byte)1;

    public static final byte FOUND             = (byte)0;
    public static final byte NOT_FOUND         = (byte)1;

    public static final byte CONTINUE          = (byte)0;
    public static final byte NOT_CONTINUE      = (byte)1;
    public static final byte NEVER_CONTINUE    = (byte)2;
}
