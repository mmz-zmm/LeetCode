struct UnionFind {
    UnionFind(int n) {
        count = n;
        parent.assign(n, 0);
        rank.assign(n, 0);

        for( int i = 0; i< n; ++i) {
          parent[i] = i;
        }
        
    }

    int find(int x) {
        return parent[x] == x ? x : find(parent[x]);
    }

    void Union(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);

        if(rootx != rooty) {
            if(rank[rootx] >= rank[rooty]) {
                parent[rooty] = rootx;
                rank[rootx] += rank[rooty];
            } else if (rank[rootx] < rank[rooty]) {
                parent[rootx] = rooty;
                rank[rooty] += rank[rootx];
            }
            --count;
        }
    }

    vector<int> parent;
    vector<int> rank;
    int count;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        if( n == 0) return 0;

        UnionFind uf(n);

        int pos = 0;
        for(int r = 0; r < n - 1; ++r) {
            for(int c = r + 1; c < n; ++c) {
                if( M[r][c] == 1) {
                    uf.Union(r,c);
                }
            }
         }

        return uf.count;
    }
};