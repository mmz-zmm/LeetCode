class Solution {
public:
    int minPairSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;
        int sum = 0;
        while (left < right) {
            sum = max(sum, nums[left] + nums[right]);
            left++;
            right--;
        }

        return sum;
    }
};