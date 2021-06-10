class Solution {
public:
    /*
    完全背包问题，定义dp[i][j]为[0,i]种硬币组成总额为j的组合的数目，对于第i种硬币来说，依然只存在两者情况，放或者不放。
    1. 不放： dp[i][j] = dp[i-1][j];
    2. 放  : dp[i][j] = dp[i][j - amount[i]]
    */
    int change(int amount, vector<int> &coins) {
        int sz = coins.size();
        if (amount == 0)
            return 1;

        vector<vector<int>> dp(sz + 1, vector<int>(amount + 1, 0));
        // amount为0,那就只有一种组合，就是没有组合。
        for (int i = 0; i <= sz; ++i) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= sz; ++i) {
            for (int j = 1; j <= amount; ++j) {
                if ((j - coins[i - 1]) >= 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[sz][amount];
    }

    //  这是最原始的解法，思考，为什么 最内层k的循环(用于表示有k个硬币)可以被替代为 dp[i - 1][j - coins[i - 1]]？
    // 实际上是因为j是从小到大逐渐递减的，
    int change2(int amount, vector<int> &coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= amount; ++j) {
                dp[i][j]  = dp[i - 1][j];
                int k = j;
                while (k >= coins[i - 1]) {
                    k -= coins[i - 1];
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }
        return dp[n][amount];
    }
};