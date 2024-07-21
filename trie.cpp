#include "trie.h"

TrieNode::TrieNode() : is_end_of_word(false) {}

Trie::Trie() : root(new TrieNode()) {}

Trie::~Trie() {
    delete_trie(root);
}

void Trie::delete_trie(TrieNode* node) {
    for (auto& pair : node->children) {
        delete_trie(pair.second);
    }
    delete node;
}

void Trie::insert(const std::string& word) {
    TrieNode* node = root;
    for (char c : word) {
        if (node->children.find(c) == node->children.end()) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->is_end_of_word = true;
}

bool Trie::search(const std::string& word) {
    TrieNode* node = root;
    for (char c : word) {
        if (node->children.find(c) == node->children.end()) {
            return false;
        }
        node = node->children[c];
    }
    return node->is_end_of_word;
}