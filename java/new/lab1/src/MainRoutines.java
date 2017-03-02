import java.io.*;

/**
 * Created by dzs on 22.02.17.
 */
public class MainRoutines {
    public static void main(String args[]) {
        switch (args.length) {
            case 0: try(Reader reader = new InputStreamReader(new FileInputStream(args[0]))) {

                    } catch (FileNotFoundException e) {
                        e.printStackTrace();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
        }
    }
}
