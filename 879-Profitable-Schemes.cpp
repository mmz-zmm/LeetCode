class Solution { 
public:
    int profitableSchemes(int n, int minProfit, vector<int> &group,
                          vector<int> &profit) {
        int len = group.size();
        int mod = 1e9 + 7;

        vector<vector<vector<int>>> dp(len+1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1)));
        dp[0][0][0] = 1;

        int member = 0;
        int earning = 0;
        for(int i = 1; i <= len; ++i) {
            member = group[i - 1];
            earning = profit[ i - 1];
            for(int j = 0; j <=n; ++j) {
                for(int k = 0; k <= minProfit; ++k) {
                    if(j < member) {
                        dp[i][j][k] = dp[i - 1][j][k];
                    } else {
                        dp[i][j][k] = (dp[i - 1][j][k] + dp[i - 1][j - member][max(0, k - earning)]) % mod;
                    }
                }
            }
        }
        int sum = 0;
        for(int j = 0; j <= n; ++j) {
            sum = (sum + dp[len][j][minProfit]) % mod;
        }

        return sum;
    }
};