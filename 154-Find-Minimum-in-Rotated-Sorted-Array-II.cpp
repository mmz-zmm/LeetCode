/**
 *  假设数组最右侧元素为x,
 * 则最小值右侧的元素都小于等于x;最小值左侧的元素都大于等于x;
 *  取数组的中点mid，如果nums[mid] < nums[right],则可以排除右侧元素, right =
 * mid,（mid可能为最小值，因此不能为mid -1）; 如果nums[mid] > nums[right],
 * 则可以排除左侧元素，即left = mid + 1，（mid不可能为最小值,因此取mid + 1）;
 *  如果nums[mid] == nums[right],
 * mid既可能在最小值左侧，也有可能则最小值右侧（因为有重复元素,如
 * 2,2,1,2,2），此时只好将 右边界逐个向左移动。
 *
 *  换个思路，可能和左边界比较。
 * */
class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;

        int mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) {
                right = mid;
            } else if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right--;
            }
        }
        return nums[left];
    }

    int findMinByLeft(vector<int> &nums) {
        int left = 0;

        int mid = 0;

        while (left < right) {
            if(nums[])
            mid = left + (right - left) / 2;
            if (nums[mid] > nums[left]) {
                left = mid + 1;
            } else if(nums[mid] < nums[left]) {
                right = mid;
            } else {
                left++;
            }
        }
        return nums[left];
    }
};