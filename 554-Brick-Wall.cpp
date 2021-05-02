class Solution {
public:
    int leastBricks(vector<vector<int>> &wall) {
        unordered_map<int, int> thick_prefix;
        int sum0 = 0;
        for (const auto &row : wall) {
            int sum = 0;
            for (auto brick : row) {
                sum += brick;
                thick_prefix[sum]++;
            }
            sum0 = sum;
        }
        thick_prefix[sum0] = 0;

        auto itr =
            max_element(thick_prefix.begin(), thick_prefix.end(),
                        [](const pair<int, int> &a, const pair<int, int> &b) {
                            return a.second < b.second;
                        });
        return wall.size() - itr->second;
    }
};