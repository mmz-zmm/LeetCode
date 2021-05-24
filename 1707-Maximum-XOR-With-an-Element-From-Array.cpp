class Solution {
public:
    const int max_bit = 30;
    struct TrieNode {
        TrieNode * nodes[2];
        TrieNode() {
            nodes[0] = nullptr;
            nodes[1] = nullptr;
        }
        ~TrieNode() {
            delete nodes[0];
            delete nodes[1];
        }     
    };

    struct Trie {
        TrieNode * root;
        Trie():root( new TrieNode()){}
        ~Trie(){
            delete root;
        }

        void insert(int num) {
            TrieNode * p = root;
            for(int k = max_bit; k >= 0; --k) {
                int pos = (num >> k) & 1;
                if(p->nodes[pos] == nullptr) {
                    p->nodes[pos] = new TrieNode();
                }
            }
        }

        int checkMaxXor(int num) {
            int res = 0;
            TrieNode * p = root;
            for(int k = max_bit; k >= 0; --k) {
                int pos = (num >> k) & 1;
                if(p->nodes[1 - pos] != nullptr) {
                    res |= 1 << k;
                    pos = 1 - pos;
                }
                p = p->nodes[pos];
            }
            return res;
        }

    };
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        for(int i = 0; i < queries.size(); ++i) {
            queries[i].push_back(i);
        }

        sort(queries.begin(), queries.end(), [](const auto& lhs, const auto & rhs){
            return lhs[1] < rhs[1];
        });

        vector<int> res(queries.size());
        Trie trie;
        int idx = 0;

        for(auto & [x, limit, pos] : queries) {
            while(idx < nums.size() && nums[idx] <= limit) {
                trie.insert(nums[idx++]);
            }

            if(idx == 0) {
                res[pos] = -1;
            } else {
                res[pos] = trie.checkMaxXor(x);
            }
        }

        return res; 
    }
};