class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        auto row = A.size();
        auto col = A[0].size();
        /*
        DFS mark the connected 1 to another flag 2
        */
        for(auto i = 0; i < row; ++i) {
            dfs(A, i, 0);
            dfs(A, i, col - 1);
        }

        for(auto j = 0; j < col; ++j) {
            dfs(A, 0, j);
            dfs(A, row - 1, j);
        }

        auto cnt = 0;
        for(const auto & row : A) {
            for( const auto & val : row) {
                if( val == 1) cnt++;
            }
        }

        return cnt;
    }

    void dfs(vector<vector<int>> & A, int i, int j) {
        if( i < 0 || i >= A.size() || j < 0 || j >= A[0].size() || A[i][j] == 0) {
            return;
        }

        A[i][j] = 0;
        dfs(A, i + 1, j);
        dfs(A, i - 1, j);
        dfs(A, i, j + 1);
        dfs(A, i, j - 1);

    }
};