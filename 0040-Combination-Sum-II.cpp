class Solution {
public:
    vector<vector<int>> lists;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.size() == 0 || target < 0)
            return lists;

        sort(candidates.begin(), candidates.end());
        vector<int> list;

        process(candidates, target, 0, list);

        return lists;
    }

    void process(const vector<int> &candidates, int target, int start, vector<int> &list)
    {
        if( target < 0)
            return;
        if( target == 0)
        {
            lists.push_back(list);
            return;
        }
        else
        {
            for(int i = start; i < candidates.size(); ++i)
            {
                // 当有重复的元素时，由于已经排序，后面元素的解空间是前面元素解空间的子集，如果后面有解，那么前面一定有解，此时就会有重复的组合，因此需要剪枝
                if( i > start && (candidates[i] == candidates[i -1]))
                    continue;
                list.push_back(candidates[i]);
                // 从当前元素下一个开始，保证该数字只使用一次
                process(candidates, target - candidates[i], i + 1, list);
                list.pop_back();
            }
        }       
    }
};