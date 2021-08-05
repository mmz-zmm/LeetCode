class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {

        int n = graph.size();
        // 三色标记法
        // 白色：未被访问;灰色：该节点位于递归栈或环上；黑色：安全节点
        enum Color { White = 0, Gray, Black };

        vector<int> color(n, White);

        function<bool(int)> safe = [&](int idx) -> bool {
            if (color[idx] > White) {
                return color[idx] == Black;
            }

            color[idx] = Gray;

            for (auto next : graph[idx]) {
                if (!safe(next)) {
                    return false;
                }
            }
            color[idx] = Black;
            return true;
        };

        vector<int> res;

        for (int i = 0; i < n; ++i) {
            if (safe(i)) {
                res.push_back(i);
            }
        }
        return res;
    }
};