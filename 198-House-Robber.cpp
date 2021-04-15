/** 动态规划
 *  dp[i]表示以i结束的序列中所能抢劫到的最大值
 *  dp[i] = max(dp[i - 2] + nums[i], dp[i - 1] + nums[i]);
 *  boundary condition: dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
 * */
class Solution {
public:
    int rob(vector<int> &nums) {
        int len = nums.size();

        if (len == 1) {
            return nums[0];
        } else if (len == 2) {
            return max(nums[0], nums[1]);
        }

        int first = nums[0];
        int second = max(nums[0], nums[1]);
        int curr = 0;

        for (auto i = 2; i < len; ++i) {
            curr = max(first + nums[i], second);
            first = second;
            second = curr;
        }
        return second;
    }
};