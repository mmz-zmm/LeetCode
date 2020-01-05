class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        return nums[sz-k];
    }
};
