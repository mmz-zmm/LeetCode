class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words) {
        unordered_map<char, int> licensePlateMap;
        for (auto c : licensePlate) {
            if (c >= 'a' && c <= 'z') {
                licensePlateMap[c]++;
            } else if (c >= 'A' && c <= 'Z') {
                licensePlateMap[tolower(c)]++;
            }
        }

        auto isComplete = [&licensePlateMap](const string &word) -> bool {
            unordered_map<char, int> word_map;
            for (auto c : word) {
                word_map[c]++;
            }

            for (auto &[c, n] : licensePlateMap) {
                if (word_map[c] < n) {
                    return false;
                }
            }
            return true;
        };

        int n = words.size();
        int idx = 0;
        int len = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (isComplete(words[i]) && words[i].size() < len) {
                idx = i;
                len = words[i].size();
            }
        }
        return words[idx];
    }
};