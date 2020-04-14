class Solution {
public:
    /*
    二维的曼哈顿距离 |x1-x2| + |y1 - y2|。
    |arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j| 可以看作是二维平面中两点的曼哈顿距离与点的索引差的和。由于i,j作为独立变量，两者在上式中可以互换，因此只用考虑i > j的场景。
    想象一下，二维平面中两个点的位置关系有四种，我们固定其中一个点(arr1_i, arr2_i)，那么另外一个点(arr1_j, arr2_j)可能在东北、西北、东南、西南，类似于田字。结合曼哈顿距离的命名来源，田字是个更容易理解的点。
    东北： -(arr1[i] - arr1[j]) - (arr2[i] - arr2[j]) + i - j
    西北：  (arr1[i] - arr1[j]) - (arr2[i] - arr2[j]) + i - j
    东南： -(arr1[i] - arr1[j]) + (arr2[i] - arr2[j]) + i - j
    西南：  (arr1[i] - arr1[j]) + (arr2[i] - arr2[j]) + i - j
    */
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        auto sz = arr1.size();
        auto max_A = INT_MIN, min_A = INT_MAX;
        auto max_B = INT_MIN, min_B = INT_MAX;
        auto max_C = INT_MIN, min_C = INT_MAX;
        auto max_D = INT_MIN, min_D = INT_MAX;

        auto tmp = 0;
        for(auto i = 0; i < sz; ++i) {
            tmp = arr1[i] + arr2[i] + i;
            max_A = max(max_A, tmp);
            min_A = min(min_A, tmp);

            tmp = arr1[i] - arr2[i] + i;
            max_B = max(max_B, tmp);
            min_B = min(min_B, tmp);

            tmp = arr2[i] - arr1[i] + i;
            max_C = max(max_C, tmp);
            min_C = min(min_C, tmp);

            tmp = - arr2[i] - arr1[i] + i;
            max_D = max(max_D, tmp);
            min_D = min(min_D, tmp);
        }

        auto cond1 = max_A - min_A;
        auto cond2 = max_B - min_B;
        auto cond3 = max_C - min_C;
        auto cond4 = max_D - min_D;

        return max(max(cond1, cond2), max(cond3, cond4));
    }
};