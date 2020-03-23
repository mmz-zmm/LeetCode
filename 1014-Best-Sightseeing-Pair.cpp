class Solution {
public:
    /*
    其实可以想到的一个办法就是两次便利，一次计算A[i] + i, 一次计算A[i] -i，
    然后计算出两个最大值即可。当然使用一次便利也可以做到，就是下面的方法。
    */
    int maxScoreSightseeingPair(vector<int>& A) {
        int res = 0;
        int pre = A[0] + 0; 

        for(auto i = 1; i < A.size(); ++i) {
            res = max(res, pre + A[i] - i);
            pre = max(pre, A[i] + i);
        }

        return res;
    }
};