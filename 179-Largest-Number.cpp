class Solution {
public:
    string largestNumber(vector<int> &nums) {
        vector<string> strs;
        strs.reserve(nums.size());

        for (auto num : nums) {
            strs.push_back(to_string(num));
        }

        sort(strs.begin(), strs.end(),
             [](const string &a, const string &b) { return b + a < a + b; });

        string res;
        for (auto &str : strs) {
            res += str;
        }
        if (res[0] == '0') {
            return "0";
        }
        return res;
    }
};