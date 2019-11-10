class Solution {
public:
    
    void swap(vector<int> &nums, int left, int right)
    {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
    }
    
    void reverse(vector<int>& nums, int start)
    {
        int i = start;
        int j = nums.size() - 1;
        while(i < j)
        {
            swap(nums, i, j);
            i++;
            j--;
        }
    }
    
    void nextPermutation(vector<int>& nums) {

        //特殊情况   
        if(nums.size() == 0 || nums.size() == 1)
            return;
        // 从后往前找到第一个满足nums[i+1]>num[i]
        int i = nums.size() - 2;
        while(i >= 0 && nums[i+1] <= nums[i])
        {
            i--;
        }
        // 根据 i的值来判断如何进一步处理
        // 整个数组已经是降序的，不存在下一个更大的排列
        if(i >= 0)
        {
            int j = nums.size() -1;
            while(j >= 0 && nums[j] <= nums[i])
            {
                j--;
            }
            swap(nums, i, j);
        }
        /* 
        如果i = -1, 表明整个数组已经是降序的，不存在下一个更大的排序，因此直接重新排列成最小的排序，即从下标0开始反转整个数组
        如果i >=0，此时已经将i 与 j位置的数字进行了交换。下标i之后的部分应该转化为升序，这样才是“下一个”更大的排列。
        */
        reverse(nums, i + 1);

    }
};