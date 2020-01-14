class Solution {
public:
    // 动态规划：
    // dp[i]:对i而言，其最少可以有几个完全平方数组成，
    //     - dp[i] 为完全平方数，dp[i] = 1
    //     - dp[i] 不为完全平方数，设 i = m + n,其中m为一个完全平方数， 则 dp[i] = dp[m] + dp[n],
    //     而dp[m] = 1,也就表明：dp[i] = 1 + dp[i - m],m是一个可以变化的值，要求得dp的最小值。
    //     那么需要一个循环进行遍历
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            // 最差情况，每个完全平方数都是1
            dp[i] = i;
            for (int j = 1; i - j * j >= 0; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};