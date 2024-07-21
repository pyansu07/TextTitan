#ifndef TRIE_H
#define TRIE_H

#include <unordered_map>
#include <string>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool is_end_of_word;

    TrieNode();
};

class Trie {
private:
    TrieNode* root;

public:
    Trie();
    ~Trie();
    void insert(const std::string& word);
    bool search(const std::string& word);
    void delete_trie(TrieNode* node);
};

#endif