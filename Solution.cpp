
#include <string>
#include <vector>
using namespace std;

class ValidWordAbbr {
    
    inline static const string NO_FILL_ABBREVIATION_SLOT = "";
    inline static const string SEVERAL_WORDS_WITH_SAME_ABBREVIATION = "*";
    unordered_map<string, string> abbreviationsToWords;
    
public:
    explicit ValidWordAbbr(const vector<string>& dictionary) {
        for (const auto& word : dictionary) {
            string abbreviation = createAbbreviation(word);
            //C++20: abbreviationsToWords.contains(abbreviation), done the old way for compatibility.
            if (abbreviationsToWords.find(abbreviation) != abbreviationsToWords.end() && abbreviationsToWords.at(abbreviation) != word) {
                abbreviationsToWords[abbreviation] = SEVERAL_WORDS_WITH_SAME_ABBREVIATION;
                continue;
            }
            abbreviationsToWords[abbreviation] = word;
        }
    }

    bool isUnique(const string& word) const {
        string abbreviation{ createAbbreviation(word)};
        return abbreviationsToWords.find(abbreviation) == abbreviationsToWords.end() || abbreviationsToWords.at(abbreviation) == word;
    }
private:
    //alternatively C++20: ...(string_view word)
    string createAbbreviation(const string& word) const {
        string abbreviation(1, word[0]);
        abbreviation.append(word.length() > 2 ? to_string(word.length() - 2) : NO_FILL_ABBREVIATION_SLOT);
        abbreviation.append(word.length() > 1 ? to_string(word[word.length() - 1]) : NO_FILL_ABBREVIATION_SLOT);
        return abbreviation;
    }
};
