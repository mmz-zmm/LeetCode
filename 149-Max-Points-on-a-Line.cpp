class Solution {
public:
    int maxPoints(vector<vector<int>> &points) {
        int n = points.size();

        int x1, y1;
        int x2, y2;
        int x3, y3;
        int res = 1;
        for (int i = 0; i < n; ++i) {
            x1 = points[i][0];
            y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                x2 = points[j][0];
                y2 = points[j][1];
                int count = 2;
                for (int k = j + 1; k < n; ++k) {
                    x3 = points[k][0];
                    y3 = points[k][1];

                    if ((y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1)) {
                        count++;
                    }
                }
                res = max(res, count);
            }
        }
        return res;
    }
};