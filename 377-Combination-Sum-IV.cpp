/** dp 
 *  假设dp[i]表示target为i的时候的组合数目，则
 *  dp[i + 1] = sum(dp[i+1 - nums[j], j= 0..n-1)
 * */
class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {

        vector<uint64_t> dp(target + 1, 0);  // target的结果应该不会溢出，因为返回值为int，但中间结果可能会溢出
        dp[0] = 1;
        for (int i = 1; i < target + 1; ++i) {
            for (auto j = 0L; j < nums.size(); ++j) {
                if (i >= nums[j]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};