class Solution {
public:
    // dp[i][j]: 从s[i]到s[j]所需的最小打印次数
    // if s[i] == s[j], dp[i][j] = dp[i][j - 1]
    // if s[i] != s[j], dp[i][j] = min(dp[i][k]... dp[k + 1]dp[j]), k in  range [i + 1, j - 1]
    // bd: dp[i][i] = 1
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for(int i = n - 1; i >=0; --i) {
            dp[i][i] = 1;
            for(int j = i + 1; j < n; ++j) {
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i][j - 1];
                } else {
                    int res = j - i + 1;
                    for(int k = i + 1; k < j; ++k) {
                        res = min(res, dp[i][k] + dp[k + 1][j]);
                    }
                    dp[i][j] = res;
                }
            }
        }

        return dp[0][n - 1];
    }
};