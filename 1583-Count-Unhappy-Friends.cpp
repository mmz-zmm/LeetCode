class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>> &preferences,
                       vector<vector<int>> &pairs) {

        vector<vector<int>> rank(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                rank[i][preferences[i][j]] = j;
            }
        }

        vector<int> matched(n);
        for (const auto &p : pairs) {
            matched[p[0]] = p[1];
            matched[p[1]] = p[0];
        }

        int res = 0;
        for (int x = 0; x < n; ++x) {
            int y = matched[x];
            int index = rank[x][y];
            for (int i = 0; i < index; ++i) {
                int u = preferences[x][i];
                int v = matched[u];
                // cout << x << " "<< y << " "<< u << " "<<v<<endl;
                if (rank[u][x] < rank[u][v]) {
                    res++;
                    break;
                }
            }
        }

        return res;
    }
};