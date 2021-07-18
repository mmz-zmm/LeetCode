class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> maps;
        int n = strs.size();
        for (int i = 0; i < n; ++i) {
            auto str = strs[i];
            sort(str.begin(), str.end());
            maps[str].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for (auto &[_, vals] : maps) {
            res.emplace_back(std::move(vals));
        }
        return res;
    }
};
