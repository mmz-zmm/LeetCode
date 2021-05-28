class Solution {
public:
    // 1. 计算数组中每个数的第i比特中0和1的数目，分别为(n -c)和c
    //  这一位上产生的数目是（n-c）*c
    // 2. 累加每一位的计算结果
    int totalHammingDistance(vector<int> &nums) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < 31; ++i) {
            int one_count = 0;
            int base = 1 << i;
            for (auto num : nums) {
                if (num & base) {
                    one_count++;
                }
            }
            res += one_count * (n - one_count);
        }
        return res;
    }
};