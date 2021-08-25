class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {

        int n = graph.size();
        vector<vector<int>> res;
        vector<int> visited(n);

        function<void(vector<int> &, int curr)> dfs = [&](vector<int> &path,
                                                          int curr) {
            if (curr == n - 1) {
                res.emplace_back(path);
                return;
            }

            for (auto node : graph[curr]) {
                if (!visited[node]) {
                    visited[node] = 1;
                    path.emplace_back(node);
                    dfs(path, node);
                    visited[node] = 0;
                    path.pop_back();
                }
            }
        };

        vector<int> path;
        path.emplace_back(0);
        dfs(path, 0);

        return res;
    }
};