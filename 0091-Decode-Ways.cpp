class Solution {
public:
    int numDecodings(string s) {

        if(s[0] == '0')
            return 0;

        vector<int> dp(s.size(), 0);
        
        dp[0] = 1;

        int number;

        for(auto i = 1; i < s.size(); ++i)
        {
            number = stoi(s.substr(i-1,2));
            if(s[i] == '0')
            {
                if(number < 10 || number > 26)
                {
                    return 0;
                }
                else
                {
                    dp[i] =  (i > 1) ? dp[i - 2]: 1;
                }
            }
            else
            {
                if(number < 10 || number > 26)
                {
                    dp[i] = dp[i - 1];
                }
                else
                {
                    dp[i] =  (i > 1) ? dp[i - 2] + dp[i - 1]: 2;
                }                
            }
        }
        return dp[s.size() - 1];
    }
};