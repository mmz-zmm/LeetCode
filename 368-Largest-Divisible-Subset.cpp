class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        // 先排序
        sort(nums.begin(), nums.end());

        // 根据动态规划的状态转移方程，获取最大子集的数目以及最大子集中的最大整数
        auto n = nums.size();
        vector<int> dp(n, 1);
        int maxSize = 1;
        int maxVal = dp[0];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                maxVal = nums[i];
            }
        }
        // 倒推出最大子集
        vector<int> res;
        res.reserve(maxSize);

        if (maxSize == 1) {
            res.push_back(nums[0]);
            return res;
        }

        for (auto i = n - 1; i >= 0 && maxSize > 0; --i) {
            if (dp[i] == maxSize && (maxVal % nums[i] == 0)) {
                res.push_back(nums[i]);
                maxVal = nums[i];
                maxSize--;
            }
        }
        return res;
    }
};