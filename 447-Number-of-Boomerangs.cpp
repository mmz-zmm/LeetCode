class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>> &points) {
        int res = 0;
        for (auto &p : points) {
            unordered_map<int, int> ump;
            for (auto &q : points) {
                int diff_x = (q[0] - p[0]);
                int diff_y = (q[1] - p[1]);
                int dis = diff_x * diff_x + diff_y * diff_y;
                ump[dis]++;
            }

            for (auto &[_, m] : ump) {
                res += m * (m - 1);
            }
        }
        return res;
    }
};