class Solution {
public:
    int titleToNumber(string columnTitle) {

        auto ctoi = [](char c) -> int { return c - 'A' + 1; };
        int n = columnTitle.size();

        int res = ctoi(columnTitle[0]);
        for (int i = 1; i < n; ++i) {
            res = res * 26 + ctoi(columnTitle[i]);
        }

        return res;
    }
};