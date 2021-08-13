class Solution {
public:
    int countDigitOne(int n) {
        int64_t i = 1;
        int res = 0;
        int rhs = 0;
        while (n) {
            int tmp = n % 10; // 当前的位置,从低位到高位，从右到左
            n /= 10;          //
            if (tmp > 1) {
                res +=
                    (n + 1) * i; // 如果这个位置大于1,前面的位置有 n + 1种取法
            } else if (tmp == 1) {
                res +=
                    n * i + rhs +
                    1; // 如果位置等于1, 其左侧的位置有n种取法，右侧有rhs种取法,
                       // 外加个位为0的场景
            } else {
                res += n * i;
            }
            rhs += tmp * i; // 记录右侧的数字
            i *= 10;        // 下一位
        }
        return res;
    }
};