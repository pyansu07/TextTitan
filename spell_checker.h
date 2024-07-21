#ifndef SPELL_CHECKER_H
#define SPELL_CHECKER_H

#include "trie.h"
#include <vector>
#include <string>

class SpellChecker {
private:
    Trie dictionary;
    std::vector<std::string> word_list;

    int levenshtein_distance(const std::string& s1, const std::string& s2);

public:
    void load_dictionary(const std::string& filename);
    bool check_word(const std::string& word);
    std::vector<std::string> suggest_corrections(const std::string& word, int max_suggestions = 5);
};

#endif