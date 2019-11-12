class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
        虽然是旋转过的有序数组，但是其中的一部分依然是有序的，所以不要被题目吓到。
        依然采用二分法查找的思想，只是处理方式有些变化。
        如果nums[mid] < nums[left], 说明[mid, right]之间一定是有序的，此时继续判断target是否在区间[mid, right]内,
        是的话选择该区间，不是的话选择另半区间。
        同样，如果nums[mid] > nums[left]，说明[left, mid]之间为有序，此时继续判断target是否在区间[left, mid]内,
        是的话选择该区间，不是的话选择另半区间。
        可以看到，每次判断，都可以将区间的范围大概减小一半，因此时间复杂度为O(logN)
        */
        if(nums.size() < 1)
            return -1;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            /*
            注意此处的<号，不能包含=号。考虑mid = left的场景，数组[3,1]，target=1，会运行到right = mid -1的地方，导致数组下标越界
            */
            if(nums[mid] < nums[left])
            {
                if(target >= nums[mid] && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                } 
            }
            else
            {
                if(target >= nums[left] && target <= nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
        } 

        return -1;     
    }
};