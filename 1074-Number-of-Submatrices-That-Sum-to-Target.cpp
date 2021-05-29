class Solution {
public:
    // 1. 使用二维数组来保存前缀和
    // 2. 假设固定子矩阵的顶部和底部，当选择一个右侧边时，计算此时[0, right]
    //  所组成的子矩阵的和为curr, 我们的目标是在左侧找到 [0,
    //  left]，使得其子矩阵和
    // 为 curr - target. 可以利用map来记录curr，用于后续的快速检索。
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> prefix_sum(row + 1, vector<int>(col + 1));

        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] -
                                   prefix_sum[i - 1][j - 1] +
                                   matrix[i - 1][j - 1];
            }
        }

        int res = 0;

        for (int top = 1; top <= row; ++top) {
            for (int bot = top; bot <= row; ++bot) {
                int cur = 0;
                int left_sum = 0;
                unordered_map<int, int> sum;
                for (int right = 1; right <= col; ++right) {
                    cur = prefix_sum[bot][right] - prefix_sum[top - 1][right];
                    if (cur == target) {
                        res++;
                    }
                    // 存在一个left位置使得满足子矩阵和为target
                    left_sum = cur - target;
                    if (sum.count(left_sum)) {
                        res += sum[left_sum];
                    }
                    sum[cur]++;
                }
            }
        }
        return res;
    }
};