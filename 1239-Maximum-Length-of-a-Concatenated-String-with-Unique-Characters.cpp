class Solution {
public:
    int strBitFormat(const string &str) {
        int res = 0;
        for (auto c : str) {
            int t = 1 << (c - 'a');
            if (res & t) {
                return -1;
            }
            res |= 1 << (c - 'a');
        }
        return res;
    }
    int maxLength(vector<string> &arr) {
        vector<vector<int>> dp(27, vector<int>{});
        dp[0] = {0};

        for (auto &str : arr) {
            int len = str.size();
            int bin = strBitFormat(str);
            if (bin < 0) {
                continue;
            }
            for (int i = 26; i >= len; i--) {
                if (dp[i - len].size()) {
                    for (auto item : dp[i - len]) {
                        if ((item & bin) == 0) {
                            dp[i].push_back(item | bin);
                        }
                    }
                }
            }
        }

        for (int i = 26; i >= 0; i--) {
            if (dp[i].size()) {
                return i;
            }
        }
        return 0;
    }

    int maxLength2(vector<string> &arr) {
        int n = arr.size();
        vector<int> masks;
        masks.reserve(n);
        for (auto &str : arr) {
            int mask = strBitFormat(str);
            if (mask > 0) {
                masks.push_back(mask);
            }
        }

        int ans = 0;
        function<void(int, int)> backtrace = [&](int pos, int mask) {
            if (pos == masks.size()) {
                ans = max(ans, __builtin_popcount(mask));
                return;
            }

            if ((mask & masks[pos]) == 0) { // mask和masks[pos]无公共元素
                backtrace(pos + 1, mask | masks[pos]);
            }

            backtrace(pos + 1, mask);
        };

        backtrace(0, 0);
        return ans;
    }
};