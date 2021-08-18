class Solution {
public:
    int checkRecord(int n) {
        /* 6个状态：
            A = 0, 非L结尾
            A = 0, L结尾
            A = 0, LL结尾
            A = 1, 非L结尾
            A = 1, L结尾
            A = 1, LL结尾
        */
        constexpr int MOD = 1'000'000'007;
        vector<int> dp(6);
        vector<int> dp_next(6);

        dp[0] = 1;

        while (n--) {
            dp_next[0] = ((dp[0] + dp[1]) % MOD + dp[2]) % MOD;
            dp_next[1] = dp[0];
            dp_next[2] = dp[1];
            dp_next[3] =
                (((((dp[0] + dp[1]) % MOD + dp[2]) % MOD + dp[3]) % MOD +
                  dp[4]) %
                     MOD +
                 dp[5]) %
                MOD;
            dp_next[4] = dp[3];
            dp_next[5] = dp[4];

            dp = dp_next;
        }

        int res = 0;
        for (auto num : dp) {
            cout << num << " ";
            res = (res + num) % MOD;
        }
        return res;
    }
};