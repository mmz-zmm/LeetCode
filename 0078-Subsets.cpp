class Solution {
public:
    vector<vector<int>> lists;
    // 回溯法
    vector<vector<int>> subsets(vector<int>& nums) {

        if(nums.size() == 0)
            return lists;
        
        vector<int> list;
        backtrace(nums, list, 0);

        return lists;
    }

    void backtrace(const vector<int> &nums, vector<int> &list, int start)
    {
        lists.push_back(list);
        for(auto i = start; i < nums.size(); ++i)
        {
            list.push_back(nums[i]);
            backtrace(nums, list, i+1);
            list.pop_back();
        }
    }
};