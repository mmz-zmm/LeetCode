class Solution {
public:
/*
* 动态规划：dp[i][j]表示从i到j的满足要求的子数组的最大值，考虑处理到第j个元素的场景：
*  dp[i][j]：
*     1. 假设arr[j]被保留，那么说明被抛弃的元素在dp[i][j-1]里面，且已经计算过了，因此最终结果为
*           dp[i][j-1] + arr[j]
*     2. 假设arr[j]被抛弃，那么说明i~(j-1)范围内不能有被抛弃的元素，也就是连续字数组的和，即
*           sum[i][j-1]
*     综合起来，dp[i][j] = max(dp[i][j-1] + arr[j], sum[i][j-1])。当然最后的结果，需要取dp和sum中的最大值

*     sum数组的计算其实也有一个要点，连续数组的最大和可能是从i到j的所有元素和，也有可能是j这个单独的元素。

*     为了降低空间复杂度，我们可以使用一个单变量进行替代dp和sum的二维数组，毕竟只用从左到右进行扫描即可，在扫描
*     的过程中，把最大值记下来就行。
*/
    int maximumSum(vector<int>& arr) {
        auto sz = arr.size();

        if (sz == 1) return arr[0];

        auto max_1 = arr[0]; // non-continuous subarray sum
        auto max_0 = arr[0]; // continuous subarray sum
        auto res = arr[0];

        for ( auto i = 1; i < sz; ++i) {
            max_1 = max(max_1 + arr[i], max_0);
            max_0 = max(max_0 + arr[i], arr[i]);

            res = max(res, max(max_1, max_0));
        }
        return res;
    }
};