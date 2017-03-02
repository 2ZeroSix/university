package wordStat;

import java.util.Arrays;
import java.util.Map;

public abstract class WordStat {
    public abstract Map<String, Long> getWordsStat();
    public int getCountOfWords() {return getWordsStat().size();}
    public String toString() {
        Map<String, Long> map = getWordsStat();
        String infoStr = "";
        @SuppressWarnings("unchecked")
        Map.Entry<String, Long>[] info = map.entrySet().toArray(new Map.Entry[0]);
        Arrays.sort(info, (a, b) -> a.getValue() < b.getValue() ?
                                    1 : (a.getValue() > b.getValue() ? -1 : 0));
        for(Map.Entry<String, Long> cur : info) {
            infoStr += cur.getKey() + ", " + cur.getValue() + ", " +
                        ((float)cur.getValue() * 100 / getCountOfWords()) + "%\n";
        }
        return infoStr;
    }

}
