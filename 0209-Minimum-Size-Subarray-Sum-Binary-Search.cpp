class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) return 0;
        
        vector<int> sums(sz+1, 0);
        for(int i = 1; i <=sz; ++i)
        {
            sums[i] = sums[i-1] + nums[i-1];
        }

        int res = INT_MAX;
        for(int i = 1; i <= sz; ++i)
        {
            int to_find = s + sums[i-1];
            auto bound = lower_bound(sums.begin(), sums.end(), to_find);
            if(bound != sums.end())
            {
                res = min(res, static_cast<int>(bound - (sums.begin() + i -1)));
            }
        }

        return (res != INT_MAX)? res:0;

    }
};