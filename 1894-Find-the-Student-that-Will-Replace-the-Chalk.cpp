class Solution {
public:
    int chalkReplacer(vector<int> &chalk, int k) {
        int n = chalk.size();
        vector<int64_t> prefix_sum(n);
        prefix_sum[0] = chalk[0];
        for (int i = 1; i < n; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + chalk[i];
        }

        int remain = k % prefix_sum[n - 1];

        auto iter = upper_bound(prefix_sum.begin(), prefix_sum.end(), remain);

        return distance(prefix_sum.begin(), iter);
    }
};