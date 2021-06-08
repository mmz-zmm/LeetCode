class Solution {
public:
    int lastStoneWeightII(vector<int> &stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);

        int target = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1));
        dp[0][0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= target; ++j) {
                if (stones[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - stones[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        for (int j = target; j >= 0; --j) {
            if (dp[n][j]) {
                return sum - 2 * j;
            }
        }
        return 0;
    }

    int lastStoneWeightII_V2(vector<int> &stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);

        int target = sum / 2;
        vector<int> dp(target + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = target; j >= 0; --j) {
                if (stones[i - 1] <= j) {
                    dp[j] = dp[j] || dp[j - stones[i - 1]];
                } else {
                    dp[j] = dp[j];
                }
            }
        }

        for (int j = target; j >= 0; --j) {
            if (dp[j]) {
                return sum - 2 * j;
            }
        }
        return 0;
    }
};
