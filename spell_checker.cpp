#include "spell_checker.h"
#include <fstream>
#include <algorithm>
#include <cctype>

void SpellChecker::load_dictionary(const std::string& filename) {
    std::ifstream file(filename);
    std::string word;
    while (std::getline(file, word)) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        dictionary.insert(word);
        word_list.push_back(word);
    }
}

bool SpellChecker::check_word(const std::string& word) {
    std::string lower_word = word;
    std::transform(lower_word.begin(), lower_word.end(), lower_word.begin(), ::tolower);
    return dictionary.search(lower_word);
}

int SpellChecker::levenshtein_distance(const std::string& s1, const std::string& s2) {
    const std::size_t len1 = s1.size(), len2 = s2.size();
    std::vector<std::vector<int>> d(len1 + 1, std::vector<int>(len2 + 1));

    for (int i = 0; i <= len1; ++i)
        d[i][0] = i;
    for (int j = 0; j <= len2; ++j)
        d[0][j] = j;

    for (int i = 1; i <= len1; ++i)
        for (int j = 1; j <= len2; ++j)
            d[i][j] = std::min({ d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]) });

    return d[len1][len2];
}

std::vector<std::string> SpellChecker::suggest_corrections(const std::string& word, int max_suggestions) {
    std::vector<std::pair<int, std::string>> suggestions;
    std::string lower_word = word;
    std::transform(lower_word.begin(), lower_word.end(), lower_word.begin(), ::tolower);

    for (const auto& dict_word : word_list) {
        int distance = levenshtein_distance(lower_word, dict_word);
        suggestions.emplace_back(distance, dict_word);
    }

    std::sort(suggestions.begin(), suggestions.end());
    
    std::vector<std::string> result;
    for (int i = 0; i < std::min(max_suggestions, static_cast<int>(suggestions.size())); ++i) {
        result.push_back(suggestions[i].second);
    }

    return result;
}