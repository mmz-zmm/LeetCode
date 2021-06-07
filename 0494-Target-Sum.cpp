class Solution {
public:
    /*
    let {postive} be set where their relation is add, {negative} be
    set where theri relaton is minus. then we get:
    sum(positive) - sum(negative) = target
    then
    sum(postive) - sum(negative) + sum(nums) = target + sum(nums)
    2 * sum(postive) = target + sum(nums)
    sum(postive) = (target + sum(nums)) / 2
    which means we need to find a set whose sum is a fixed "new target"
    */
    int findTargetSumWays(vector<int> &nums, int S) {
        int sz = nums.size();
        if (sz == 0)
            return 0;

        int sum = accumulate(nums.begin(), nums.end(), 0);
        // 数组的和小于S,不存在解决方法；如果sum +
        // S为奇数，也不存在解决方法，因为上面的方程无解
        if (sum < S || (sum + S) % 2) {
            return 0;
        }

        int new_target = (sum + S) / 2;
        vector<int> dp(new_target + 1, 0);
        dp[0] = 1; // 当目标为0时，只有一种可能，就是什么数都不取
        for (int i = 0; i < sz; ++i) {
            for (int j = new_target; j >= nums[i]; --j) {
                dp[j] = dp[j] + dp[j - nums[i]];
            }
        }
        return dp[new_target];
    }
    // 根据 sum(positive) + sum(negtive) = sum(all), sum(positive) - sum(negtive) = target, 可以得出
    // sum(negtive) = (sum(all) - target) / 2;
    // 进而问题转化为在数组中挑选若干元素使得其和为某个固定值。
    int findTargetSumWays2(vector<int> &nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int diff = sum - target;
        if (diff < 0 || diff % 2 != 0) {
            return 0;
        }
        int n = nums.size();
        int neg = diff / 2;
        vector<vector<int>> dp(n + 1, vector<int>(neg + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            int num = nums[i - 1];
            for (int j = 0; j <= neg; ++j) {
                if (j >= num) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - num];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][neg];
    }
};