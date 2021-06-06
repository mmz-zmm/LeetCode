class Solution {
public:
    vector<int> getZeroAndOneFromStr(const string &s) {
        vector<int> res(2);
        res[0] =
            count_if(s.begin(), s.end(), [](const char c) { return c == '0'; });

        res[1] = s.size() - res[0];

        return res;
    }
    int findMaxForm(vector<string> &strs, int m, int n) {
        int length = strs.size();
        vector<vector<vector<int>>> dp(
            length + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));

        int zeros = 0;
        int ones = 0;
        for (int i = 1; i <= length; ++i) {
            vector<int> counts = getZeroAndOneFromStr(strs[i - 1]);
            zeros = counts[0];
            ones = counts[1];
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    // 不考虑加入第i个字符串
                    dp[i][j][k] = dp[i - 1][j][k];
                    // 考虑加入第i个字符串
                    if (j >= zeros && k >= ones) {
                        dp[i][j][k] = max(dp[i - 1][j][k],
                                          dp[i - 1][j - zeros][k - ones] + 1);
                    }
                }
            }
        }
        return dp[length][m][n];
    }
};