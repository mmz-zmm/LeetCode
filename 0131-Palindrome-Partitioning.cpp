class Solution {
public:
    vector<vector<string>> lists;
    vector<vector<string>> partition(string s) { 
        if(s.size() == 0)
            return lists;
        
        auto len = s.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));

        for(auto right = 0; right < len; ++right)
        {
            for(auto left = 0; left <= right;++left)
            {
                if(s[left] == s[right] && (right -left <=2 || dp[left+1][right-1]))
                {
                    dp[left][right] = 1;
                }
            }
        }

        vector<string> list;
        backtrace(s, 0, dp, list);
        return lists;
    }
    void backtrace(const string & s, int start, const vector<vector<int>> &dp, vector<string> & list)
    {
        if(start == s.size())
        {
            lists.push_back(list);
            return;
        }

        for(auto  i = start; i < s.size(); ++i)
        {
            if(dp[start][i])
            {
                list.push_back(s.substr(start, i-start + 1));
                backtrace(s, i+1, dp, list);
                list.pop_back();
            }
        }
    }
};~