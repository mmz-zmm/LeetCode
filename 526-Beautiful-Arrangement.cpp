class Solution {
public:
    int countArrangement(int n) {

        vector<vector<int>> match(n + 1);
        vector<int> visited(n + 1);
        int num = 0;

        function<void(int)> backtrace = [&](int index) {
            if (index == n + 1) {
                num++;
                return;
            }

            for (auto x : match[index]) {
                if (!visited[x]) {
                    visited[x] = true;
                    backtrace(index + 1);
                    visited[x] = false;
                }
            }
        };

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i % j == 0 || j % i == 0) {
                    match[i].push_back(j);
                }
            }
        }
        backtrace(1);
        return num;
    }
};

class Solution2 {
public:
    int countArrangement(int n) {
        int max_n = 1 << n;
        vector<int> dp(max_n);
        dp[0] = 1;

        for (int mask = 1; mask < max_n; ++mask) {
            int num = __builtin_popcount(mask);
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i) &&
                    (num % (i + 1) == 0 || (i + 1) % num == 0)) {
                    dp[mask] += dp[mask ^ (1 << i)];
                }
            }
        }
        return dp[max_n - 1];
    }
};