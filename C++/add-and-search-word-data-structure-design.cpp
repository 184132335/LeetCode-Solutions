// Time:  O(min(n, h)), per operation
// Space: O(min(n, h))

class WordDictionary {
public:
    struct TrieNode{
    public:
        bool isString = false;
        unordered_map<char, TrieNode *> leaves;
    };

    WordDictionary(){
        root_ = new TrieNode();
        root_->isString = true;
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
            auto* p = root_;
            for (const auto& c : word) {
                if (p->leaves.find(c) == p->leaves.cend()) {
                    p->leaves[c] = new TrieNode;
                }
                p = p->leaves[c];
            }
            p->isString = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchWord(word, root_, 0);
    }

    bool searchWord(string word, TrieNode* node, int s) {
        if (s == word.length()) {
            return node->isString;
        }
        if (node->leaves.find(word[s]) != node->leaves.end()){ // Match the char.
            return searchWord(word, node->leaves[word[s]], s + 1);
        } else if (word[s] == '.') { // Skip the char.
            for (const auto& i : node->leaves) {
                if (searchWord(word, i.second, s + 1)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    TrieNode *root_;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
