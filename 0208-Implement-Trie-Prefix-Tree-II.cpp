class Trie {
public:
    /** Initialize your data structure here. */
    Trie() { root = new TrieNode(); }
    ~Trie() { delete root; }

    /** Inserts a word into the trie. */
    void insert(string word) {
        if (word.empty()) {
            return;
        }

        TrieNode *p = root;
        p->path++;
        int index = 0;
        for (auto &c : word) {
            index = c - 'a';
            if (!p->map[index]) {
                p->map[index] = new TrieNode();
            }

            p = p->map[index];
            p->path++;
        }
        p->end++;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (word.empty()) {
            return false;
        }

        TrieNode *p = root;
        int index = 0;
        for (auto &c : word) {
            index = c - 'a';
            if (!p->map[index]) {
                return false;
            }
            p = p->map[index];
        }
        return p->end != 0;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) {
        if (prefix.empty()) {
            return false;
        }

        TrieNode *p = root;
        int index = 0;
        for (auto &c : prefix) {
            index = c - 'a';
            if (!p->map[index]) {
                return false;
            }
            p = p->map[index];
        }
        return p->path != 0;
    }

private:
    struct TrieNode {
        int path;
        int end;
        TrieNode *map[26];
        TrieNode() : path(0), end(0) {
            for (auto &node : map) {
                node = nullptr;
            }
        }
        ~TrieNode() {
            for (auto &node : map) {
                delete node;
            }
        }
    };
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);