class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
        int n = quiet.size();
        vector<vector<int>> richer_map(n);
        for (const auto &vec : richer) {
            richer_map[vec[1]].push_back(vec[0]);
        }

        vector<int> answer(n, -1);

        function<void(int)> dfs = [&](int idx) {
            if (answer[idx] != -1) {
                return;
            }
            answer[idx] = idx;

            for (auto j : richer_map[idx]) {
                dfs(j);
                if (quiet[answer[j]] < quiet[answer[idx]]) {
                    answer[idx] = answer[j];
                }
            }
        };

        for (int i = 0; i < n; ++i) {
            dfs(i);
        }

        return answer;
    }
};