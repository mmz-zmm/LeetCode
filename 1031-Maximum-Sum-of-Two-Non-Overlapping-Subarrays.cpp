class Solution {
public:
/* 动态规划
* A_sum[i] : 表示前i个数的和
  sum_L[i] 表示前i个数中子数组长度位L的最大和
  sum_M[i] 表示前i个数中子数组长度位M的最大和
  sum[i] 表示前i个数中由L和M组成的最大和
*/
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        auto sz = A.size();
        vector<int> A_sum(sz+1);
        vector<int> sum_L(sz+1);
        vector<int> sum_M(sz+1);
        vector<int> sum(sz+1);

        for(auto i = 1 ; i <= sz; ++i) {
            // 注意 右侧为 i - 1
            A_sum[i] = A_sum[i - 1] + A[i - 1];
            if( i >= L) {
                sum_L[i] = max(sum_L[i-1], A_sum[i] - A_sum[i - L]);
            }
            if(i >= M) {
                sum_M[i] = max(sum_M[i-1], A_sum[i] - A_sum[i - M]);
            }
        }
        // 状态转移，sum[i] 与sum[i-1]之间的关系
        for( auto i = L+M; i <= sz; ++i) {
            // L在左侧，A[i-1] 属于 M的范围内
            auto case1 = sum_L[i - M] + (A_sum[i] - A_sum[i - M]);
            // M在左侧，A[i-1] 属于L的范围内
            auto case2 = sum_M[i - L] + (A_sum[i] - A_sum[i - L]);
            // case3, A[i-1]不在L和M的范围内，此时 sum[i] =sum[i -1]
            sum[i] = max(sum[i - 1], max(case1, case2)); 
        }

        //dbg(A_sum);cout<< endl;
        //dbg(sum_L);cout<<endl;
        //dbg(sum_M);cout<<endl;
        //dbg(sum);cout<<endl;

        return sum[sz];
    }

    void dbg(const vector<int> & vec) {
        for_each(vec.begin(),vec.end(), [](int val){cout<<val<<"  ";});
    }
};
