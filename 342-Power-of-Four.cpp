class Solution {
public:
    // 开方后可以归为2的幂
    bool isPowerOfFour(int n) {
        if (n <= 0) {
            return false;
        }

        int square_root = sqrt(n);
        if (square_root * square_root != n) {
            return false;
        } else {
            return !(square_root & (square_root - 1));
        }
    }
    // 构造一个mask,偶数位位1，即 10101010101010101010101010101010
    // 表示为16进制为 AAAAAAAA
    bool isPowerOfFour2(int n) {
        return n > 0 && !(n & (n - 1)) && !(n & 0xAAAAAAAA);
    }
};