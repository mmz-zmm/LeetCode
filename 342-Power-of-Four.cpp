class Solution {
public:
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
};