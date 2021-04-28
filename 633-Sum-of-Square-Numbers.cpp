class Solution {
public:
    bool judgeSquareSum(int c) {
        int limit = sqrt(c);
        int left = 0;
        int right = limit;
        int remain = c - right * right;
        int a_square = left * left;
        while (left <= right) {
            if (a_square == remain) {
                return true;
            } else if (a_square > remain) {
                right--;
                remain = c - right * right;
            } else {
                left++;
                a_square = left * left;
            }
        }
        return false;
    }
};