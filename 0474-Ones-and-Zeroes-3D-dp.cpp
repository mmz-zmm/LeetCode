class Solution {
public:
    /*
    转化为0-1背包问题。将0和1的个数看做是背包的容量,将各个字符串看做是物品。每个字符串都有两个选择，放或者不放。
    dp[i][j][k]表示字符串数组子区间[0,i]内使用j个0和k个1能拼出的字符串的最大数目
    第i个字符串不放入： dp[i][j][k] = dp[i-1][j][k]
               放入： dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j - zeros][k - ones])
               其中，zeros和ones是第i个字符串中0和1的个数。
    */
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        if( sz == 0 ) return 0;
        
        typedef vector<vector<int>> vector_2D;
        typedef vector<vector<vector<int>>> vector_3D;
        vector_3D dp(sz + 1, vector_2D(m + 1, vector<int>(n + 1)));

        for(int i = 1; i <= sz; ++i) {
            vector<int> cnt = countZeroAndOne(strs[i - 1]);
            for(int j = 0; j <= m; ++j) {
                for( int k = 0; k <=n; ++k) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    
                    int zeros = cnt[0];
                    int ones = cnt[1];
                    if(j >= zeros && k >= ones) {
                        dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-zeros][k-ones] + 1);
                    }
                }
            }
        }
        return dp[sz][m][n];
    }
    
    vector<int> countZeroAndOne(const string& str) {
        vector<int> cnt(2);
        for( auto c : str) {
            cnt[ c- '0']++;
        }
        return cnt;
    }
};