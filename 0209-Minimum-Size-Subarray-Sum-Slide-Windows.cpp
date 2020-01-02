class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) return 0;
        int left = 0;
        int cur = 0;
        int res = INT_MAX;
        for(int right = 0; right < sz; ++right)
        {
            cur += nums[right];
            while(cur >=s)
            {
                res = min(res, right -left + 1);
                cur -= nums[left];
                left += 1;
            }
        }

        return res == INT_MAX ? 0: res;
    }
};