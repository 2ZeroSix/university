package md5.general;

import java.net.InetAddress;
import java.util.UUID;

public class Info {
    public static final int MAX_LENGTH          = 300000;
    public static final int STEP                = 10000;

    public static final int SERVER_PORT         = 5000;
    public static final String SERVER_IP_STRING = "127.0.0.1";

    public static final char[] ALPHABET         = {'A', 'C', 'G', 'T'};

    public static final int MAX_TIME_FOR_TASK   = 10000;//10 sec

    public static final int UUID_LENGTH         = UUID.randomUUID().toString().getBytes().length;
}
