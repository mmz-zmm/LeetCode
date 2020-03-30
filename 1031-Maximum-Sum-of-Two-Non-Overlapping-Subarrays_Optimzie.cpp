class Solution {
public:
/* 动态规划
* A_sum[i] : 表示前i个数的和
  sum_L = A_sum[i] - A_sum[i - L] L个数的和
  sum_M = A_sum[i] - A_sum[i - M] M个数的和
*/
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        auto sz = A.size();
        vector<int> A_sum(sz+1);
        for(auto i = 1 ; i <= sz; ++i) {
            // 注意 右侧为 i - 1
            A_sum[i] = A_sum[i - 1] + A[i - 1];
        }

        auto sum_L = A_sum[L];
        auto sum_M = A_sum[M];
        auto res = A_sum[L + M];
        // 状态转移，res[i] 与res[i - 1]之间的关系
        for( auto i = L+M; i <= sz; ++i) {
            // L个数的最大和
            sum_L = max(sum_L, A_sum[i - M] - A_sum[i - M - L]);
            // M个数的最大和
            sum_M = max(sum_M, A_sum[i - L] - A_sum[i - L - M]);
            // res[i-1]: 此时A[i-1]不属于L或M
            // 第二项: A[i - 1] 属于M
            // 第三项：A[i-1]属于L
            res = max(res, max(sum_L + A_sum[i] - A_sum[i - M], sum_M + A_sum[i] - A_sum[i - L]))
;        }
        return res;
    }
};
