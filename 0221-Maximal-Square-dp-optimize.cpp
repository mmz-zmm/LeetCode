class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        /*
        二维数组：
        dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1
        一维数组,从左至右扫描:
        dp[j] = min(dp[j-1],dp[j],prev), prev = dp[j-1]
        (prev)
       dp[j-1])---dp[j]   round 1
            |       |
            |       |
        dp[j-1]---dp[j]   round 2
                  (new)
        */
        int rows = matrix.size();
        if( rows == 0) 
            return 0;
        int cols = matrix[0].size();
        vector<int> dp(cols+1, 0);
        int maxsqlen = 0;
        int prev_dp = 0;
        int temp = 0;
        for(int i = 1; i <=rows; ++i){
            for(int j = 1; j <=cols; ++j){
                temp = dp[j];
                if(matrix[i-1][j-1] == '1'){
                    dp[j] = min(min(dp[j-1],dp[j]), prev_dp) + 1;  //
                    maxsqlen = max(maxsqlen, dp[j]);
                }
                else{
                    dp[j] = 0;
                }
                prev_dp = temp;
            }
            
        }
        return maxsqlen * maxsqlen;

    }
};
