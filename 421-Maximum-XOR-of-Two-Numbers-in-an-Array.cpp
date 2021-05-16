struct Trie {
    struct TrieNode {
        TrieNode *node[2];
        TrieNode(){
            for (auto &t : node) {
                t = nullptr;
            }
        }
        ~TrieNode() {
            for (auto &t : node) {
                delete t;
            }
        }
    };
    Trie() { root = new TrieNode();}
    ~Trie() { delete root; }

    void insert(int num) {
        TrieNode * p = root;
        for(int k = 30; k >= 0; --k) {
            if((num >> k) & 1) {
                if(!p->node[1]) {
                    p->node[1] = new TrieNode();
                }
                p = p->node[1];
            } else {
                if(!p->node[0]) {
                    p->node[0] = new TrieNode();
                }
                p = p->node[0];                
            }
        }
    }

    int xorQuery(int num) {
        int res = 0;
        TrieNode *p = root;
        for(int i = 30; i >= 0; --i) {
            if((num >> i) & 1) {
                if(p->node[0]) {
                    res = res * 2 + 1;
                    p = p->node[0];
                } else {
                    p =  p->node[1];
                    res = res * 2;
                }
            } else {
                if(p->node[1]) {
                    res = res * 2 + 1;
                    p = p->node[1];
                } else {
                    p = p->node[0];
                    res = res * 2;
                }
            }
        }

        return res;
    }

    TrieNode * root;
};

class Solution {
public:
    int findMaximumXOR(vector<int> &nums) {
        int res = 0;
        Trie trie;
        for(int i = 1; i < nums.size(); ++i) {
            trie.insert(nums[i - 1]);
            res = max(res, trie.xorQuery(nums[i]));
        }

        return res;
    }

};