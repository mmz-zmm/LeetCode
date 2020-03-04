class Solution {
public:
    /*
    dp[n][k]: 移动次数为n,鸡蛋个数为k，所能检测到的最大层数
    dp[n-1][k]:鸡蛋没碎
    dp[n-1][k-1]：鸡蛋碎了
    1、无论你在哪层楼扔鸡蛋，鸡蛋只可能摔碎或者没摔碎，碎了的话就测楼下，没碎的话就测楼上。

    2、无论你上楼还是下楼，总的楼层数 = 楼上的楼层数 + 楼下的楼层数 + 1（当前这层楼）

    */
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(N+1, vector<int>(K+1, 0));

        int n = 0;
        while(dp[n][K] < N) {
            n++;
            for(int k = 1; k <= K; ++k) {
                dp[n][k] = dp[n - 1][k - 1] + dp[n - 1][k] + 1;
            }
        }
        return n;
    }
};
