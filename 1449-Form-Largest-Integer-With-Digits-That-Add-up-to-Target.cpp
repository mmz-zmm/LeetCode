class Solution {
public:
    // version 1: 2d dp.
    // 问题转化：构成target的数字的数目越多，最终的结果值越大
    // 数目相同的情况下，优先取数字大的作为开头，因此可以从后往前进行选择。
    // 这样就转化为两个问题：
    // 1.
    // 选取若干个数，使得所有数的和为target，同时个数最多。可以看作是总价为target，选取最多物品，每个物品无限次选取的背包问题。
    // 2. 从高位向低位遍历，如果dp[j] == dp[j - cost[i]]，则说明选择了i,
    // 此时结果上加上该位对应的数字。
    string largestNumber(vector<int> &cost, int target) {
        int sz = cost.size();

        vector<vector<int>> dp(sz + 1, vector<int>(target + 1, -5001));
        vector<vector<int>> trace(sz + 1, vector<int>(target + 1));
        dp[0][0] = 0;

        int not_count = 0;
        int count = 0;
        for (int i = 1; i <= sz; ++i) {
            for (int j = 0; j <= target; ++j) {
                if (j < cost[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                    trace[i][j] = j;
                } else {
                    not_count = dp[i - 1][j];
                    count = dp[i][j - cost[i - 1]] + 1;

                    dp[i][j] = max(not_count, count);
                    trace[i][j] = (not_count > count) ? j : (j - cost[i - 1]);
                }
            }
        }

        // for(int i = 0; i <= sz; ++i) {
        //     for(int j = 0; j <= target; ++j) {
        //         cout << dp[i][j]<<"  ";
        //     }
        //     cout << endl;
        // }

        // cout << "**\n";
        // for(int i = 0; i <= sz; ++i) {
        //     for(int j = 0; j <= target; ++j) {
        //         cout << trace[i][j]<<"  ";
        //     }
        //     cout << endl;
        // }
        if (dp[sz][target] < 0) {
            return "0";
        }

        string res;
        int i = 9;
        int j = target;
        while (i > 0) {
            if (j == trace[i][j]) {
                --i;
            } else {
                res += '0' + i;
                j = trace[i][j];
            }
        }

        return res;
    }
    // version 2: 使用1d dp，去掉跟踪位置的额外数组
    string largestNumber2(vector<int> &cost, int target) {
        int sz = cost.size();

        vector<int> dp(target + 1, -5001);
        dp[0] = 0;

        for (int i = 1; i <= sz; ++i) {
            for (int j = cost[i - 1]; j <= target; ++j) {
                dp[j] = max(dp[j], dp[j - cost[i - 1]] + 1);
            }
        }

        if (dp[target] < 0) {
            return "0";
        }

        string res;
        for (int i = sz, j = target; i >= 1; i--) {
            int u = cost[i - 1];
            while (j >= u && dp[j] == dp[j - u] + 1) {
                res += '0' + i;
                j -= u;
            }
        }
        return res;
    }
};
