class Solution {
public:
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target) {
        // Manhattan Distance
        int me = abs(target[0]) + abs(target[1]);

        for (auto &ghost : ghosts) {
            if (abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]) <= me) {
                return false;
            }
        }
        return true;
    }
};