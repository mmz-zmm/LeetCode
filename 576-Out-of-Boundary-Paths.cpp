class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        constexpr int MOD = 1'000'000'007;
        vector<vector<int>> direcctions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        int totalCounts = 0;
        // dp[i][j][k]: 球移动i次后位于坐标(j,k)的路径数量
        vector<vector<vector<int>>> dp(maxMove + 1,
                                       vector<vector<int>>(m, vector<int>(n)));
        dp[0][startRow][startColumn] = 1;
        for (int i = 0; i < maxMove; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < n; ++k) {
                    int count = dp[i][j][k];
                    if (count > 0) {
                        for (auto &direction : direcctions) {
                            int j1 = j + direction[0];
                            int k1 = k + direction[1];
                            if (j1 >= 0 && j1 < m && k1 >= 0 && k1 < n) {
                                dp[i + 1][j1][k1] =
                                    (dp[i + 1][j1][k1] + count) % MOD;
                            } else {
                                totalCounts = (totalCounts + count) % MOD;
                            }
                        }
                    }
                }
            }
        }
        return totalCounts;
    }
};

class Solution2 {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        constexpr int MOD = 1'000'000'007;
        vector<vector<int>> direcctions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        int totalCounts = 0;
        // dp[i][j][k]: 球移动i次后位于坐标(j,k)的路径数量
        // 第一维仅依赖前一次，可以省略以节省空间
        vector<vector<int>> dp(m, vector<int>(n));
        dp[startRow][startColumn] = 1;
        for (int i = 0; i < maxMove; ++i) {
            vector<vector<int>> dpNext(m, vector<int>(n));
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < n; ++k) {
                    int count = dp[j][k];
                    if (count > 0) {
                        for (auto &direction : direcctions) {
                            int j1 = j + direction[0];
                            int k1 = k + direction[1];
                            if (j1 >= 0 && j1 < m && k1 >= 0 && k1 < n) {
                                dpNext[j1][k1] = (dpNext[j1][k1] + count) % MOD;
                            } else {
                                totalCounts = (totalCounts + count) % MOD;
                            }
                        }
                    }
                }
            }
            dp = std::move(dpNext);
        }
        return totalCounts;
    }
};