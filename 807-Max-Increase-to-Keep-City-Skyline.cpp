class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<int> row_max;
        vector<int> col_max;
        for (auto &row : grid) {
            row_max.push_back(*max_element(row.begin(), row.end()));
        }

        for (int j = 0; j < n; ++j) {
            int max_col_item = 0;
            for (int i = 0; i < n; ++i) {
                max_col_item = max(max_col_item, grid[i][j]);
            }
            col_max.push_back(max_col_item);
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // cout << row_max[i] << " "<< col_max[j] << "
                // "<<grid[i][j]<<endl;
                res += (min(row_max[i], col_max[j]) - grid[i][j]);
            }
        }
        return res;
    }
};