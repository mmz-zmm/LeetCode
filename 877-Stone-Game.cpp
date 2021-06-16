class Solution {
public:
    // dp[i][j]:
    // 当剩下的石子堆的范围为i到j时，当前玩家与另一玩家石子数量差的最大值。
    bool stoneGame(vector<int> &piles) {
        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; ++i) {
            dp[i][i] = piles[i];
        }

        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] =
                    max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }

        return dp[0][n - 1] > 0;
    }

    bool stoneGame2(vector<int> &piles) {
        int n = piles.size();

        vector<int> dp(n);

        for (int i = 0; i < n; ++i) {
            dp[i] = piles[i];
        }

        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                dp[j] = max(piles[i] - dp[j], piles[j] - dp[j - 1]);
            }
        }

        return dp[n - 1] > 0;
    }
};