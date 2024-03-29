// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int row;
        int col;
        int idx;
        do {
            row = rand7();
            col = rand7();
            idx = (row - 1) * 7 + col;
        } while (idx > 40);

        return idx % 10 + 1;
    }
};