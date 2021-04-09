class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while(right > 0 && nums[0] ==nums[right]) {
            right--;
        }
        int mid = 0;
        int target = nums[right];
        while(left < right) {
            mid = left + (right - left)/2;
            if(nums[mid] <= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};