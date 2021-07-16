class Solution {
public:
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        // if(n == 1) {
        //     return target == nums[0] ? 1 : 0;
        // }
        int left = 0;
        int right = n;
        int mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int low = left;
        left = low;
        right = n;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
            s
        }

        int high = left;

        return high - low;
    }
};