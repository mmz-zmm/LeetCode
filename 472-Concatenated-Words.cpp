class Solution {
public:
    struct Trie {
        vector<Trie *> children;
        bool isEnd;
        Trie() : children(vector<Trie *>(26, nullptr)), isEnd(false) {
            // cout << "--new--"<<endl;
        }
        ~Trie() {
            for (auto child : children) {
                if (child) {
                    delete child;
                    // cout << "--delete--"<<endl;
                }
            }
        }
    };
    struct TrieTree {
        TrieTree() { root = new Trie(); }
        ~TrieTree() { delete root; }
        Trie *root;
        void insert(const string &word) {
            Trie *node = root;
            for (auto c : word) {
                int idx = c - 'a';
                if (!node->children[idx]) {
                    node->children[idx] = new Trie();
                }
                node = node->children[idx];
            }
            node->isEnd = true;
        }
    };
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        TrieTree tree;

        vector<string> res;
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });

        function<bool(const string &word, int start)> dfs =
            [&](const string &word, int start) {
                if (start == word.size()) {
                    return true;
                }

                Trie *node = tree.root;

                for (int i = start; i < word.size(); i++) {
                    int idx = word[i] - 'a';
                    node = node->children[idx];
                    if (!node) {
                        return false;
                    }

                    if (node->isEnd) {
                        if (dfs(word, i + 1)) {
                            return true;
                        }
                    }
                }
                return false;
            };

        for (auto &word : words) {
            if (word.size() == 0) {
                continue;
            }
            if (dfs(word, 0)) {
                res.emplace_back(word);
            } else {
                // cout << "insert "<< word <<endl;
                tree.insert(word);
            }
        }

        return res;
    }
};