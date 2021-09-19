class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= n; ++i) {
            dp[i] = INT_MAX;
            for (int j = 1; j * j <= i; j++) {
                // 从j个字符变为i个字符，需要经历一次CopyAll, i/j -
                // 1次Paste，共i/j次操作。
                if (i % j == 0) {
                    int divide = i / j;
                    dp[i] = min(dp[i], dp[j] + divide);
                    dp[i] = min(dp[i], dp[divide] + j);
                }
            }
        }
        return dp[n];
    }
};