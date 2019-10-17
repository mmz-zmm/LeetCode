class Solution
{
public:
    string longestPalindrome(string s)
    {
#ifdef VERSION_1
        // 动态规划
        int **dp = nullptr;
        size_t len = s.size();
        /*
       动态创建二维数组
       */
        dp = new int *[len];
        for (auto i = 0; i < len; ++i)
        {
            dp[i] = new int[len]();
        }

        int L = 0;
        int R = 0;
        /*
       动态规划，dp[i][j] = dp[i+1][j-1], s[i]==s[j,代表从i到j的字串是否回文
        */
        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (j == i)
                {
                    dp[i][j] = 1;
                }
                else if (j - i == 1 && (s[i] == s[j]))
                {
                    dp[i][j] = 1;
                }
                else if (s[i] == s[j] && (dp[i + 1][j - 1]))
                {
                    dp[i][j] = 1;
                }

                if ((dp[i][j]) && j - i > (R - L))
                {
                    R = j;
                    L = i;
                }
            }
        }

        /*
        释放二维数组
       */
        for (auto i = 0; i < len; ++i)
        {
            delete[] dp[i];
        }
        delete[] dp;

        return s.substr(L, R - L + 1);
#endif

#ifdef VERSION_2
        /* 
        Manacher 算法
        https://leetcode-cn.com/problems/longest-palindromic-substring/solution/5-zui-chang-hui-wen-zi-chuan-cc-by-bian-bian-xiong/
        */
        size_t len = s.size();
        if( len <= 1)
            return s;
        // 字符串预处理，添加#
        string new_s(len * 2 + 1, '#');
        for(size_t i = 0; i < len; ++i){
            new_s[2*i + 1] = s[i];
        }
        
        int max_right = 0;   // 当前访问到的所有回文字符串，所能到达的最右的位置
        int max_right_pos = 0; // max_right对应的对称轴的位置
        
        int max_RL = 0;      // 记录最大的回文子串的回文半径
        int max_RL_pos = 0; // 对应最大回文子串的对称轴位置
        
        len = new_s.size();   
        int *RL = new int[len](); // 辅助数组，每一位记录当前位置字符的回文半径， RL[i] = right - pos + 1
        for(int i = 0; i < len; ++i){
            
            if( i < max_right){
                RL[i] = min(RL[2*max_right_pos - i], max_right - i + 1); // i 在max_right左边，利用已知信息
            }else{
                RL[i] = 1;  // i 在max_right右边,全新的回文子串
            }
            
            // 从当前的回文半径向外扩展
            while( (i - RL[i] >= 0) && (i + RL[i] < len) 
                  && new_s[i - RL[i]] == new_s[i+RL[i]]){
                RL[i] ++;
            }
            
            // 更新最优边界和对称轴
            if( i + RL[i] - 1 > max_right){  
                max_right = i + RL[i] - 1;
                max_right_pos = i;
            }
            
            // 更新最大回文串的回文半径和位置
            if(max_RL < RL[i]){
                max_RL = RL[i];
                max_RL_pos = i;
            }

        }
        delete [] RL;
        // max_RL - 1 就是原字符回文串的长度, 辅助数组下标除以2得到原数组下标
        return s.substr((max_RL_pos - max_RL +1)/2, max_RL -1);
#endif
    }
};