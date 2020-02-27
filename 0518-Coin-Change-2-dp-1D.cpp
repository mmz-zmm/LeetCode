class Solution {
public:
    /*
    完全背包问题，定义dp[i][j]为[0,i]种硬币组成总额为j的组合的数目，对于第i种硬币来说，依然只存在两者情况，放或者不放。
    1. 不放： dp[i][j] = dp[i-1][j];
    2. 放  : dp[i][j] = dp[i][j - amount[i]]
    */
    int change(int amount, vector<int>& coins) {
        int sz = coins.size();
        if( amount == 0) return 1;

        vector<int> dp(amount + 1, 0);
        // amount为0,那就只有一种组合，就是没有组合。
        dp[0] = 1;

        for (int i = 1; i <= sz; ++i) {
            for (int j = 1; j <= amount; ++j) {
                if( (j - coins[i-1]) >= 0) {
                    dp[j] = dp[j] + dp[j-coins[i-1]];
                }
            }
        } 
        return dp[amount];
    }
};