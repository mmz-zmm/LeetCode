class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        int mid = 0;
        while(left <= right) {
            mid = left + (right - left)/2;

            if(nums[mid] == target) {
                return true;
            }

            if(nums[mid] < nums[right]) {
                if(target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            } else if(nums[mid] > nums[right]) {
                if(target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                right--;
            }
        }
        return false;
    }
};