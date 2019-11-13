class Solution {
public:
    vector<vector<int>> lists;
    /*
    参考两位大佬的分析文章，讲述回溯法的，思路清晰
    1. https://leetcode-cn.com/problems/combination-sum/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-2/
    2. https://leetcode-cn.com/circle/article/GV6eQ2/
    */
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size() == 0 || target < 0)
        {
            return lists;
        }
        vector<int> list;
        process(candidates, target, 0, list);
        return lists;
    }

    void process(vector<int> &candidates, int target, int start, vector<int> &list)
    {
        if(target < 0)
            return;
        
        if(target == 0)
        {
            lists.push_back(list);
        }
        else
        {
            for(int i = start; i < candidates.size(); ++i)
            {
                list.push_back(candidates[i]);
                process(candidates, target - candidates[i], i, list);
                /*
                关于此处的pop_back，开始可能不太理解。引用一位大佬的话，
                回溯算法的思想是“尝试每一次可能性”，这种尝试的前提是：每次尝试之前所有变量的值
                要一样（即“初始状态是一样的”）。
                打个比方，就好比你在一个迷宫之中，想要找出所有能够走出迷宫的路，那么当你沿某个路径
                走出去之后，不论这条路的结局是成功还是失败，你在进行下一次尝试的时候，还是要回到最初
                的原点。
                */
                list.pop_back();
            }
        }
        
    }
};