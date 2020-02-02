class Solution {
public:
    // 二分查找的关键是找出“查找空间”。有两种查找空间：基于下标的和基于范围的（最大值和最小值之间的范围）。
    // 大多数情况，如果数组是在一个方向上有序，我们使用下标作为搜索空间。如果数组无序，我们使用范围作为搜索空间。
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];
        while( left < right) {
            int mid = left + (right - left)/2;
            int count = 0;
            int j = n - 1;
            for(int i = 0; i < n; ++i) {
                while (j >= 0 && matrix[i][j] > mid) j--;
                count += (j + 1);
            }
            if(count < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};