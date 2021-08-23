class Solution {
public:
    int getMaximumGenerated(int n) {
        int res = 0;

        unordered_map<int, int> maps;
        maps[0] = 0;
        maps[1] = 1;

        int half = 0;
        int remain = 0;
        for (int i = 1; i <= n; ++i) {
            half = i / 2;
            remain = i % 2;
            if (remain == 0) {
                maps[i] = maps[half];
            } else {
                maps[i] = maps[half] + maps[half + 1];
            }

            res = max(res, maps[i]);
        }

        return res;
    }
};