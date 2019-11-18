class Solution {
public:
    /*
    先排序，随后依次合并区间
    */
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if(intervals.size() < 2)
            return intervals;

        sort(intervals.begin(), intervals.end(), cmp);

        vector<vector<int>> res;

        res.push_back(intervals[0]);
        
        for( auto i = 1; i < intervals.size(); ++i)
        {
            if(intervals[i][0] > res.back()[1])
            {
                res.push_back(intervals[i]);
            }
            else
            {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }

        return res;
    }

    inline static bool cmp(const vector<int> &lhs, const vector<int> &rhs)
    {
        return lhs[0] < rhs[0];
    }
}; 