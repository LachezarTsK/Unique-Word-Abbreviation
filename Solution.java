
import java.util.HashMap;
import java.util.Map;

public class ValidWordAbbr {

    private static final String NO_FILL_ABBREVIATION_SLOT = "";
    private static final String SEVERAL_WORDS_WITH_SAME_ABBREVIATION = "*";
    private Map<String, String> abbreviationsToWords;

    public ValidWordAbbr(String[] dictionary) {
        abbreviationsToWords = new HashMap<>();
        for (String word : dictionary) {
            String abbreviation = createAbbreviation(word);
            if (abbreviationsToWords.containsKey(abbreviation) && !abbreviationsToWords.get(abbreviation).equals(word)) {
                abbreviationsToWords.put(abbreviation, SEVERAL_WORDS_WITH_SAME_ABBREVIATION);
                continue;
            }
            abbreviationsToWords.put(abbreviation, word);
        }
    }

    public boolean isUnique(String word) {
        String abbreviation = createAbbreviation(word);
        return !abbreviationsToWords.containsKey(abbreviation) || abbreviationsToWords.get(abbreviation).equals(word);
    }

    private String createAbbreviation(String word) {
        StringBuilder abbreviation = new StringBuilder();
        abbreviation.append(word.charAt(0));
        abbreviation.append(word.length() > 2 ? word.length() - 2 : NO_FILL_ABBREVIATION_SLOT);
        abbreviation.append(word.length() > 1 ? word.charAt(word.length() - 1) : NO_FILL_ABBREVIATION_SLOT);
        return abbreviation.toString();
    }
}
