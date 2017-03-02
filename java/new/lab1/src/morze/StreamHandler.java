package morze;

import java.io.InputStream;
import java.io.OutputStream;

/**
 * Created by dzs on 01.03.17.
 */
public interface StreamHandler {
    public String handle(InputStream is, OutputStream os);
}
