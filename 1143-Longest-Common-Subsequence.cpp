/**
 * Try dynamic programming. DP[i][j] represents the longest common subsequence of text1[0 ... i] & text2[0 ... j].
 * DP[i][j] = DP[i - 1][j - 1] + 1 , if text1[i] == text2[j] DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]) , otherwise
 **/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1= text1.size();
        int len2 = text2.size();

        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));

        for(int i = 1; i <= len1; ++i) {
            for(int j = 1; j <= len2; ++j) {
                if(text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[len1][len2];
    }
};