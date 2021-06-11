class Solution {
public:
    // 动态规划：
    // dp[i]:对i而言，其最少可以有几个完全平方数组成，
    //     - dp[i] 为完全平方数，dp[i] = 1
    //     - dp[i] 不为完全平方数，设 i = m + n,其中m为一个完全平方数， 则 dp[i]
    //     = dp[m] + dp[n], 而dp[m] = 1,也就表明：dp[i] = 1 + dp[i -
    //     m],m是一个可以变化的值，要求得dp的最小值。 那么需要一个循环进行遍历
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            // 最差情况，每个完全平方数都是1
            dp[i] = i;
            for (int j = 1; i - j * j >= 0; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
    // base version: 2d dp
    // 与换硬币问题类似，每个平方数都可以取无数个，且平方数的选择的固定范围的
    int numSquares1(int n) {
        int sz = floor(sqrt(n));
        vector<int> squares(sz);
        for (int i = 0; i < sz; ++i) {
            squares[i] = (sz - i) * (sz - i);
        }

        vector<vector<int>> dp(sz + 1, vector<int>(n + 1, 10000));

        dp[0][0] = 0;

        for (int i = 1; i <= sz; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (j >= squares[i - 1]) {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - squares[i - 1]] + 1);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[sz][n];
    }

    // version 2: use 1d dp
    int numSquares2(int n) {
        int sz = floor(sqrt(n));
        vector<int> squares(sz);
        for (int i = 0; i < sz; ++i) {
            squares[i] = (sz - i) * (sz - i);
        }

        vector<int> dp(n + 1, 10000);

        dp[0] = 0;

        for (int i = 1; i <= sz; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (j >= squares[i - 1]) {
                    dp[j] = min(dp[j], dp[j - squares[i - 1]] + 1);
                } else {
                    dp[j] = dp[j];
                }
            }
        }

        return dp[n];
    }

    // version 3: shorten the range
    int numSquares3(int n) {
        int sz = floor(sqrt(n));
        vector<int> squares(sz);
        for (int i = 0; i < sz; ++i) {
            squares[i] = (sz - i) * (sz - i);
        }

        vector<int> dp(n + 1, 10000);

        dp[0] = 0;

        for (int i = 1; i <= sz; ++i) {
            for (int j = squares[i - 1]; j <= n; ++j) {

                dp[j] = min(dp[j], dp[j - squares[i - 1]] + 1);
            }
        }
    }
    // version 4: no need extra space to store squares
    int numSquares(int n) {
        int sz = floor(sqrt(n));

        vector<int> dp(n + 1, 10000);

        dp[0] = 0;

        for (int i = sz; i >= 1; --i) {
            int curr_square = i * i;
            for (int j = curr_square; j <= n; ++j) {

                dp[j] = min(dp[j], dp[j - curr_square] + 1);
            }
        }

        return dp[n];
    }
};