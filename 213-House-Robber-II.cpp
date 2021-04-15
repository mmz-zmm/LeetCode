/** 动态规划
 *  dp[i]表示以i结束的序列中所能抢劫到的最大值
 *  dp[i] = max(dp[i - 2] + nums[i], dp[i - 1] + nums[i]);
 *  boundary condition: dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
 *  
 *  与198题不一样的地方在于，首与尾相邻，偷了首就不能偷尾，因此可以分解为两个问题：
 *  [1,n-1]与[2,n]两个区间进行分别计算，最后再取最大值
 * */
class Solution {
public:
    int rob(vector<int> &nums) {
        int len = nums.size();
        if (len == 1) {
            return nums[0];
        }
        if (len == 2) {
            return max(nums[0], nums[1]);
        }

        return max(maxRobByRange(nums, 0, len - 1),
                   maxRobByRange(nums, 1, len));
    }

    int maxRobByRange(const vector<int> &nums, int left, int right) {

        int len = right - left;

        int first = nums[left];
        int second = max(nums[left], nums[left + 1]);
        int curr = 0;

        for (auto i = 2; i < len; ++i) {
            curr = max(first + nums[i + left], second);
            first = second;
            second = curr;
        }
        return second;
    }
};