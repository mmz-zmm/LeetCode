class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        int n = nums.size();
        int pre_sum = 0;
        int max_len = 0;
        unordered_map<int, int> pre_sums;
        pre_sums[pre_sum] = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                pre_sum++;
            } else {
                pre_sum--;
            }
            if (pre_sums.count(pre_sum)) {
                max_len = max(max_len, i - pre_sums[pre_sum]);
            } else {
                pre_sums[pre_sum] = i;
            }
        }

        return max_len;
    }
};