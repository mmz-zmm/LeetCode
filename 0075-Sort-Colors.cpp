class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 方法1：冒泡排序
        if(nums.size() == 0)
            return;

        for(auto i = 0; i < nums.size() - 1; ++i)
        {
            for(auto j = 0; j < nums.size() - 1 -  i; ++j)
            {
                if( nums[j] > nums[j+1])
                {
                    std::swap(nums[j], nums[j+1]);
                }
            }
        }
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 方法2：使用三个变量，分别记录红色、白色和蓝色的位置，类似于双指针法
        if(nums.size() == 0)
            return;

        int zero_pos = 0;
        int two_pos = nums.size() - 1;

        for(auto i = 0; i <= two_pos;)
        {
            if(nums[i] == 0)
            {
                swap(nums[zero_pos], nums[i]);
                zero_pos++;
                i++;
            }
            else if( nums[i] == 2)
            {
                swap(nums[two_pos], nums[i]);
                two_pos--;
            }
            else
            {
                i++;
            }
        }
    }

    void swap(int & lhs, int &rhs)
    {
        if(lhs == rhs)
            return;
        
        std::swap(lhs, rhs);
    }
};