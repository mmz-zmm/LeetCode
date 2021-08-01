class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
        using Val = pair<int, int>;
        auto cmp = [](const Val &lhs, const Val &rhs) -> bool {
            return lhs.second > rhs.second ||
                   (lhs.second == rhs.second && lhs.first > rhs.first);
        };

        priority_queue<Val, vector<Val>, decltype(cmp)> pq(cmp);

        int n = mat.size();
        int solder = 0;
        for (int i = 0; i < n; ++i) {
            solder = accumulate(mat[i].begin(), mat[i].end(), 0);
            pq.push(make_pair(i, solder));
        }

        vector<int> res;
        res.reserve(k);

        for (int i = 0; i < k; ++i) {
            auto &val = pq.top();
            res.push_back(val.first);
            pq.pop();
        }
        return res;
    }
};