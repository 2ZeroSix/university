package wordStat;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Reader;
import java.util.HashMap;
import java.util.Map;

public class FileWordStatHashMap extends WordStat {
    private Map<String, Long> map;
    public FileWordStatHashMap(String fileName) {
        map = new HashMap<>();
        stat(fileName);
    }

    private void stat(String fileName) {
        try (Reader reader = new InputStreamReader(new FileInputStream(fileName))) {
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
            System.err.println("Error while reading file: " + e.toString());
        }
    }

    private void addWord(StringBuilder builder) {
        if (builder.length() > 0) {
            Long previousValue = map.get(builder.toString());
            if (previousValue == null) {
                previousValue = 0L;
            }
            map.put(builder.toString(), previousValue + 1L);
            builder.setLength(0);
        }
    }

    public Map<String, Long> getWordsStat() {
        return map;
    }
}
