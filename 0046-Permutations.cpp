class Solution {
public:
    vector<vector<int>> lists;
    // 还是使用回溯法
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0) 
            return lists;
        vector<int> log(nums.size(), 0);
        vector<int> list(nums.size());
        process(nums, list, 0, log);
        return lists;
    }

    void process(const vector<int> & nums, vector<int> &list, int pos, vector<int> &log )
    {
        if(pos > nums.size() - 1)
        {
            lists.push_back(list);
            return;
        }
            
        for(int i = 0; i < nums.size(); i++){
            if(!log[i])
            {
                log[i] = 1;
                list[pos] = nums[i];
                process(nums, list, pos+1, log);
                log[i] = 0;
            }
        }
    }
};