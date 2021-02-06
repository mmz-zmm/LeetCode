// 逆向思维：不是求最小的前缀+后缀，而是求最大的子数组，使得该字数组的和为sum(nums) - x,
// 且长度最长。这里采用滑动窗口方法，当 sum == target的时候，不断 “前缀”+“后缀”的最小长度

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int size = nums.size();

        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        
        if (target == 0) {
            return size;
        }

        int left = 0;
        int sum = 0;
        int ret = size;
        for(int right = 0; right < size; ++ right) {
            sum += nums[right];
            while(sum > target && left < right) {
                sum -= nums[left];
                left++;
            }
            if(sum == target) {
                ret = min(ret, size - (right - left + 1));
            }
        }
        if (ret == size) {
            return -1;
        }
        return ret;

    }
};