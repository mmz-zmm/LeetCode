class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int sz = s.size();
        if ( sz < 2) return sz;

        vector<vector<int>> dp(sz, vector<int>(sz, 0));
        for(int i = sz - 1; i >= 0; --i) {
            for(int j = i; j < sz; ++j) {
                if(i == j) {
                    dp[i][j] = 1;
                } else if(s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][sz - 1];
    }
};