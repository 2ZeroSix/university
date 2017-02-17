package first_task;

// import first_task.WordStat;
import java.lang.*;
import java.io.*;
import java.util.*;

public class FileWordStatHashMap implements WordStat {
    private Map<String, Long> map;
    private long countOfWords;
    public FileWordStatHashMap(String fileName) {
        long countOfWords = 0;
        map = new HashMap<String, Long>();
        stat(fileName);
    }

    private void stat(String fileName) {
        Reader reader = null;
        try {
            reader = new InputStreamReader(new FileInputStream(fileName));
            StringBuilder builder = new StringBuilder();
            char characters[] = new char[256];
            while(reader.ready()) {
                int countOfFineChars = reader.read(characters,0, 256);
                for (int i = 0; i < countOfFineChars; ++i) {
                    if (Character.isLetterOrDigit(characters[i])) {
                        builder.append(characters[i]);
                    } else {
                        addWord(builder);
                    }
                }
            }
            addWord(builder);
        }
        catch (IOException e) {
            System.err.println("Error while reading file: " + e.getLocalizedMessage());
        }
        finally {
            if (reader != null) {
                try {
                    reader.close();
                }
                catch (IOException e) {
                    e.printStackTrace(System.err);
                }
            }
        }
    }

    private void addWord(StringBuilder builder) {
        if (builder.length() > 0) {
            ++countOfWords;
            Long previousValue = map.get(builder.toString());
            if (previousValue == null) {
                previousValue = Long.valueOf(0);
            }
            map.put(builder.toString(), previousValue + Long.valueOf(1));
            builder.setLength(0);
        }
    }

    public Map getWordsStat() {
        return map;
    }

    public String toString() {
        String infoStr = new String();
        @SuppressWarnings("unchecked")
        Map.Entry<String, Long>[] info = map.entrySet().toArray(new Map.Entry[0]);

        Arrays.sort(info, (Map.Entry<String, Long> first, Map.Entry<String, Long> second) -> {
            return first.getValue() < second.getValue() ? 1 : (first.getValue() > second.getValue() ? -1 : 0);});
        for(int i = 0; i < info.length; ++i) {
            Map.Entry<String, Long> cur = info[i];
            infoStr += cur.getKey() + ", " + cur.getValue() + ", " + ((float)cur.getValue() * 100 / countOfWords) +  "%\n";
        }
        return infoStr;
    }
}
