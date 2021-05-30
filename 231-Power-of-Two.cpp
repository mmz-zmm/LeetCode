class Solution {
public:
    // 幂不可能为负
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        return !(n & (n - 1));
    }
};