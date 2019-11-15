class Solution {
public:
    vector<vector<int>> lists;
    vector<vector<int>> permuteUnique(vector<int>& nums) {      
        if(nums.size() == 0)
            return lists;

        sort(nums.begin(), nums.end());

        vector<int> list(nums.size());
        vector<int> visited(nums.size(), 0);
        backtrace(nums, list, 0, visited);

        return lists;
    }

    void backtrace(const vector<int> &nums, vector<int> &list, int current, vector<int> &visited)
    {
        if(current == nums.size())
        {
            lists.push_back(list);
            return;
        }
        
        for(int i = 0; i < nums.size(); ++i)
        {
            // 跳过重复元素。数组排序之后，i-1位置的解空间必然包括了i位置的解空间，因此要跳过i；求解i-1的解空间，那么i-1必须被访问过。
            if( i > 0  && visited[i-1] &&  nums[i] == nums[i-1])
                continue;
            if(!visited[i])
            {
                list[current] = nums[i];
                visited[i] = 1;
                backtrace(nums, list, current + 1, visited);
                visited[i] = 0;
            }
        }
    }
};