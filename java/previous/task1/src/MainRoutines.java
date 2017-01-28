package first_task;

import java.lang.*;

public class MainRoutines {
    public static void main(String args[]) {
        WordStat statBuilder = new FileWordStatHashMap(args[0]);
        System.out.println(statBuilder);
    }
}