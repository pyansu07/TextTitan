#include "spell_checker.h"
#include <iostream>

int main() {
    SpellChecker spell_checker;
    spell_checker.load_dictionary("dictionary.txt");

    std::string word;
    while (true) {
        std::cout << "Enter a word (or 'quit' to exit): ";
        std::cin >> word;

        if (word == "quit") {
            break;
        }

        if (spell_checker.check_word(word)) {
            std::cout << "'" << word << "' is spelled correctly." << std::endl;
        } else {
            std::cout << "'" << word << "' might be misspelled. Suggestions:" << std::endl;
            auto suggestions = spell_checker.suggest_corrections(word);
            for (const auto& suggestion : suggestions) {
                std::cout << "  " << suggestion << std::endl;
            }
        }
    }

    return 0;
}