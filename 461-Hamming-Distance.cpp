class Solution {
public:
    // 1. 异或获取不同的bit位(为1)
    // 2. 计算1的数目
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int res = 0;
        while (z) {
            z = z & (z - 1);
            res++;
        }
        return res;
    }
};