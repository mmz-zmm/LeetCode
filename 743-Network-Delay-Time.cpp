class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {

        constexpr int DIS_INF = INT_MAX / 2;
        // 邻接矩阵储存节点间信息
        vector<vector<int>> g(n, vector<int>(n, DIS_INF));
        int src = 0;
        int dst = 0;
        int weight = 0;

        for (auto &edge : times) {
            src = edge[0] - 1;
            dst = edge[1] - 1;
            g[src][dst] = edge[2];
        }

        // 从源点到其它节点的距离数组
        vector<int> dist(n, DIS_INF);
        dist[k - 1] = 0;

        // 节点是否被访问数组
        vector<int> visited(n);

        for (int i = 0; i < n; ++i) {
            // 在未访问的节点中找到距离源点最近的点
            int pos = -1;
            for (int j = 0; j < n; ++j) {
                if (!visited[j] && (pos == -1 || dist[j] < dist[pos])) {
                    pos = j;
                }
            }
            // 该节点被设置为已访问
            visited[pos] = 1;
            // 更新源距离其它节点的距离
            for (int j = 0; j < n; ++j) {
                dist[j] = min(dist[j], dist[pos] + g[pos][j]);
            }
        }
        // 找到距离源点最远的点
        int res = *max_element(dist.begin(), dist.end());

        return (res == DIS_INF) ? -1 : res;
    }
};