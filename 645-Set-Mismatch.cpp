class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int n1 = n - 1;
        int act_sum = 0;
        int replicate = 0;
        for (int i = 0; i < n1; ++i) {
            if (nums[i] == nums[i + 1]) {
                replicate = nums[i];
            }
            act_sum += nums[i];
        }
        act_sum += nums[n1];

        int expect_sum = static_cast<int>((1 + n) * (n / 2.0));

        int miss = expect_sum - (act_sum - replicate);
        return {replicate, miss};
    }
};