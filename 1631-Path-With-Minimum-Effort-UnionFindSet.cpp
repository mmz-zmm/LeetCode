// 将相邻点之前的高度差作为权值，构造一个包含两边及权值的边数组，随后根据权值边数组进行排序
// 随后构建一个并查集，按权值由小到大依次添加边到并查集，每次添加后都检查 左上角元素和右下角元素
// 是否已经在同一个集合中，如果是，则当前的全集就已经是最小的，也就是题目中待求的最小体力消耗值
class Solution {
public:
    
    struct UnionFindSet {
        vector<int> parents_;
        vector<int> ranks_;

        UnionFindSet(int n): parents_(n), ranks_(n, 1) {
            iota(parents_.begin(), parents_.end(), 0);
        }

        int Find(int u) {
            while(parents_[u] != u) {
                parents_[u] = parents_[parents_[u]];
                u = parents_[u];
            }
            return u;
        }

        bool Union(int u, int v) {
            int pu = Find(u);
            int pv = Find(v);

            if(pu == pv) {
                return false;
            }

            if(ranks_[pu] == ranks_[pv]) {
                parents_[pv] = pu;
                ranks_[pu]++;
            } else if (ranks_[pu] > ranks_[pv]) {
                parents_[pv] = pu;
            } else {
                parents_[pu] = pv;
            }
            return true;
        }

        bool Connected(int u, int v) {
            return Find(u) == Find(v);
        }
    };

    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        if(row == 1 && col == 1) {
            return 0;
        }
        
        vector<tuple<int, int , int>> edges;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j ) {
                int id = i * col + j;
                if (i > 0) {
                    edges.emplace_back(id - col, id, abs(heights[i][j] - heights[i - 1][j]));
                }
                if (j > 0) {
                    edges.emplace_back(id - 1, id, abs(heights[i][j] - heights[i][j - 1]));
                }
            }
        }

        sort(edges.begin(), edges.end(), [](const auto& e1, const auto &e2){
            auto && [u1, v1, w1] = e1;
            auto && [u2, v2, w2] = e2;
            return w1 < w2;
        });

        UnionFindSet uf(row * col);
        int ans = 0;
        const int target = row * col - 1; 
        for(const auto &[u,v, w] : edges) {
            uf.Union(u, v);
            if( uf.Connected(0, target)) {
                ans = w;
                break;
            }
        }
        return ans;
    }
        
};