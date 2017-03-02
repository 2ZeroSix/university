import java.lang.*;
import wordStat.*;
public class MainRoutines {
    public static void main(String args[]) {
        if (args.length > 0) {
            WordStat statBuilder = new FileWordStatHashMap(args[0]);
            System.out.println(statBuilder);
        }
        else {
            System.out.println("First argument must be a name of file");
        }
    }
}