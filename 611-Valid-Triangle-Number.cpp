class Solution {
public:
// 首先是排序，从小到大。
// 接着，我们先固定最大的边，其下标为i，作为主循环变量
// 随后，令first为最短边下标，second为次短边，其初始值分别为0和i-1;
// 判断nums[first] + nums[second] <= nums[i]是否成立：
// 如成立，则当前组合无法组成三角形(不满足两边和大于第三边)，此时仅移动左边界first（不需要移动右边界，因为它左侧的值更小）,
// 如不成立，则当前组合可以组成三角形，[first, second)内的数值与second, i均可以组成三角形。此时累加res，second左移。
// 由此，first和second的移动为单方向，直到相遇。

    int triangleNumber(vector<int> &nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int res = 0;
        for (int i = n - 1; i >= 0; --i) {
            int second = i - 1;
            int first = 0;
            while (first < second) {
                if (nums[first] + nums[second] <= nums[i]) {
                    first++;
                } else {
                    res += (second - first);
                    second--;
                }
            }
        }
        return res;
    }