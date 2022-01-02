class Solution {
public:
    int lastRemaining(int n) {
        int head = 1;
        int left = true;
        int step = 1;

        while (n > 1) {
            if (left || n % 2 != 0) {
                head += step;
            }
            step <<= 1;
            n >>= 1;
            left = !left;
        }

        return head;
    }
};