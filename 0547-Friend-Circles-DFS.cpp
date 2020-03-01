class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        if( n == 0) return 0;

        vector<int> visited(n, 0);
        int circles = 0;
        for( int i = 0; i < n ; ++ i) {
            if( !visited[i]) {
                dfs(M, visited, i);
                circles++;
            }
        }
        return circles;
    }

    void dfs(const vector<vector<int>> & M, vector<int> &visited, int i) {
        for( int j = 0; j < M.size(); ++j) {
            if( !visited[j] && M[i][j] == 1) {
                visited[j] = 1;
                dfs(M, visited, j);
            }
        }
    }
};