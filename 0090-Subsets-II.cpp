class Solution {
public:
    /*
    与78题子集的不同之处在于 nums可能包含重复元素，且解集不能包含重复子集。这可以通过两个步骤解决。
    1. 把数组先排序
    2. 进行回溯时，检查当前要开始的数组是否与前一个数组元素相同，如果相同，则其解集已经包含在前者的回溯结果中了，直接跳过
    */
    vector<vector<int>> lists;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        if(nums.size() == 0)
        {
            lists.push_back({});
            return lists;
        }

        sort(nums.begin(), nums.end());

        vector<int> list;
        backtrace(nums, list, 0);

        return lists;
    }

    void backtrace(const vector<int> &nums, vector<int> list, int start)
    {
        lists.push_back(list);
  
        for(auto i = start; i < nums.size(); ++i)
        {
            // 此处跳过相同的元素
            if( i != start && nums[i] == nums[i -1])
            {
                continue;
            }
            list.push_back(nums[i]);
            backtrace(nums, list, i+1);
            list.pop_back();
        }
    }
};