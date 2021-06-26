class Solution {
public:
    int slidingPuzzle(vector<vector<int>> &board) {
        string start;
        int zero_pos;
        start.reserve(6);
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 0) {
                    zero_pos = i * 3 + j;
                }
                start.push_back(board[i][j] + '0');
            }
        }
        if (start == "123450") {
            return 0;
        }
        // string, zero_pos, step
        queue<tuple<string, int, int>> q;
        unordered_set<string> visited;
        q.emplace(start, zero_pos, 0);
        visited.emplace(start);
        int next[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        auto getNextState =
            [&next, &visited](const string &start,
                              int zero_pos) -> vector<pair<string, int>> {
            vector<pair<string, int>> res;
            int old_row = zero_pos / 3;
            int old_col = zero_pos % 3;
            for (int i = 0; i < 4; ++i) {
                int new_row = old_row + next[i][0];
                if (new_row < 0 || new_row > 1) {
                    continue;
                }
                int new_col = old_col + next[i][1];
                if (new_col < 0 || new_col > 2) {
                    continue;
                }
                int zero_new_pos = new_row * 3 + new_col;
                string new_start = start;
                std::swap(new_start[zero_pos], new_start[zero_new_pos]);
                if (visited.find(new_start) == visited.end()) {
                    res.emplace_back(new_start, zero_new_pos);
                }
            }
            return res;
        };

        while (!q.empty()) {
            auto [state, zero_pos1, step] = q.front();
            // cout << state << "-"<< zero_pos1<<"-"<<step<<endl;
            q.pop();
            auto &&next_states = getNextState(state, zero_pos1);
            for (auto &[str, zero_pos2] : next_states) {
                if (str == "123450") {
                    return step + 1;
                } else {
                    if (visited.find(str) != visited.end()) {
                        continue;
                    }
                    visited.emplace(str);
                    q.emplace(str, zero_pos2, step + 1);
                }
            }
        }
        return -1;
    }
};