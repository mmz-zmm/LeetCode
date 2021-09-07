class Solution {
public:
    // 贪心算法，遇到L加，遇到R减,当结果为0时，结果加一
    int balancedStringSplit(string s) {
        int count = 0;
        int left_num = 0;
        for (auto c : s) {
            if (c == 'L') {
                left_num++;
            } else {
                left_num--;
            }
            if (left_num == 0) {
                count++;
            }
        }
        return count;
    }
};