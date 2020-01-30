class Solution {
public:
    // dp[i] : 金额为i时所需的最少硬币数
    // dp[i] = min{dp[i], dp[i - coins[j]]}, j表示第j种面值的硬币
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(auto a = 1; a <= amount; ++a) {
            for(const auto & coin : coins) {
                if(a >= coin && dp[a - coin] < INT_MAX) {
                    dp[a] = min(dp[a], dp[a - coin] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
