class Solution {
public:
    int search(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size();
        int mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return nums[left] == target ? left : -1;
    }
};