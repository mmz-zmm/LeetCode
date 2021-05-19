class Solution {
public:
    // 异或的性质 a^b ^a = b，利用前缀和来进行快速的计算
    // pre[i][j] = pre[i - 1][j] ^ pre[i][j-1] ^ pre[i - 1][j-1] ^ nums[i][j]，类似于面积法
    int kthLargestValue(vector<vector<int>> &matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> prefix_sum(m + 1, vector<int>(n + 1, 0));
        priority_queue<int, vector<int>, greater<int>> heap;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                prefix_sum[i][j] = prefix_sum[i - 1][j] ^ prefix_sum[i][j - 1] ^
                                   prefix_sum[i - 1][j - 1] ^
                                   matrix[i - 1][j - 1];
                heap.push(prefix_sum[i][j]);
                if (heap.size() > k) {
                    heap.pop();
                }
            }
        }
        return heap.top();
    }
};