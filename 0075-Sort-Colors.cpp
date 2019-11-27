class Solution {
public:
    void sortColors(vector<int>& nums) {

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