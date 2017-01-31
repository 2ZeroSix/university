import javax.swing.SwingUtilities;
import sapper.*;

public class MainRoutines {
    public static void main(String args[]) {
        SwingUtilities.invokeLater(new sapper.Game());
    }
}