class Solution {
public:
// Floyd-Warshall's algorithm
// 两点间最短距离算法核心：dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 10001));
        for(const auto & edge: edges) {
            int from = edge[0];
            int to = edge[1];
            dist[from][to] = edge[2];
            dist[to][from] = edge[2];
        }
        for(auto i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }

        for(auto k = 0; k < n; ++k) {
            for(auto i = 0; i < n; ++i) {
                for (auto j = 0; j < n; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int ret = 0;
        int minCount = n;
        for(auto i = 0; i < n ; ++i) {
            int count = 0;
            // 统计满足条件的次数
            for(const auto& dis : dist[i]) {
                if (dis <= distanceThreshold) {
                    count++;
                }
            }
            // 保存最小的次数
            if (count <= minCount) {
                minCount = count;
                ret = i;
            }
        }
        return ret;


    }
};