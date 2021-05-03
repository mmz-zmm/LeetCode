class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int left_limit = INT_MIN / 10;
        int right_limit = INT_MAX / 10;
        while (x) {
            if (res < left_limit || res > right_limit) {
                return 0;
            }
            res = res * 10 + x % 10;
            x /= 10;
        }

        if (x < 0) {
            res = -res;
        }
        return res;
    }
};