class Solution {
public:
    /*
    转化为0-1背包问题。将0和1的个数看做是背包的容量,将各个字符串看做是物品。每个字符串都有两个选择，放或者不放。
    dp[i][j][k]表示字符串数组子区间[0,i]内使用j个0和k个1能拼出的字符串的最大数目
    第i个字符串不放入： dp[i][j][k] = dp[i-1][j][k]
               放入： dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j - zeros][k - ones])
               其中，zeros和ones是第i个字符串中0和1的个数。
    可以优化为2-D,因为当前的状态只与上一次的状态有关，但是要注意，遍历的顺序需要反过来，从右往左ll
    */
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        if( sz == 0 ) return 0;
        
        typedef vector<vector<int>> vector_2D;
        vector_2D dp(m + 1, vector<int>(n + 1));

        for(int i = 1; i <= sz; ++i) {
            vector<int> cnt = countZeroAndOne(strs[i - 1]);
            int zeros = cnt[0];
            int ones = cnt[1];
            for(int j = m; j >= zeros; j--) {
                for( int k = n; k >=ones; k--) {   
                    dp[j][k] = max(dp[j][k], dp[j-zeros][k-ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
    
    vector<int> countZeroAndOne(const string& str) {
        vector<int> cnt(2);
        for( auto c : str) {
            cnt[ c- '0']++;
        }
        return cnt;
    }
};