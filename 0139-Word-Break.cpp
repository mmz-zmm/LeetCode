class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.size() == 0)
            return false;
        
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;

        for(auto i = 0;  i < s.size(); ++i)
        {
            if(dp[i])
            {
                for(auto j = i + 1; j < dp.size(); ++ j)
                {
                    if( find(wordDict.begin(), wordDict.end(), s.substr(i, j - i)) != wordDict.end())
                    {
                        dp[j] = 1;
                    }
                }
            }
        }
        return dp[s.size()];
    }

  
};