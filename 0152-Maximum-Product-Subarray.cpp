class Solution {
public:
    int maxProduct(vector<int>& nums) {

        if(nums.size() == 0)
            return 0;

        int res = nums[0];
        int pre_max = nums[0];
        int pre_min = nums[0];
        int temp;
       
        for(auto i = 1; i < nums.size(); ++ i)
        {
            temp = pre_min;
            pre_min = min(nums[i], min(pre_max * nums[i], pre_min * nums[i]));
            pre_max = max(nums[i], max(pre_max * nums[i], temp * nums[i]));
            res = max(res, pre_max);
        }

        return res;
    }
};