class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n));

        // dp[i][j]中i的变化依赖于i + 1, 表明依赖于下一行,因此i需要从大到小遍历
        // j的变化依赖于j - 1，因此j需要从小到大遍历
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                // 两边字符相等，则回文子串可以向两侧扩展(+2)
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    // 两边字符不相等，则取子串中的最大值
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};