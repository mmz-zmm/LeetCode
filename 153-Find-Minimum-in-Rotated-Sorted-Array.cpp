class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        int mid = 0;
        while(left <= right) {
            if(nums[left] <= nums[right]) {
                return nums[left];
            }
            mid = left + (right - left)/2;

            if(nums[left] <= nums[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};