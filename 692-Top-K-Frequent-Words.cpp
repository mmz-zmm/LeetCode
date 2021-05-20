class Solution {
public:
    vector<string> topKFrequent(vector<string> &words, int k) {

        vector<string> res;

        map<string, int> words_cnt;
        for (auto &word : words) {
            words_cnt[word]++;
        }

        auto cmp = [&words_cnt](const string &lhs, const string &rhs) {
            return words_cnt[rhs] < words_cnt[lhs] ||
                   (words_cnt[rhs] == words_cnt[lhs] && lhs < rhs);
        };
        map<string, int, decltype(cmp)> words_kth(cmp);

        for (auto &[key, val] : words_cnt) {
            words_kth.emplace(key, val);
            if (words_kth.size() > k) {
                words_kth.erase(--words_kth.end());
            }
        }

        for (auto &[key, val] : words_kth) {
            res.push_back(key);
        }
        return res;
    }
};