class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        if (board[0][0] != -1) {
            return -1;
        }
        int N = board.size();
        int id_max = N * N;

        auto getPosById = [&N](int id) -> pair<int, int> {
            int id_actual = id - 1;
            int row = id_actual / N;
            int col = id_actual % N;
            if (row % 2 == 1) {
                col = N - col - 1;
            }

            return make_pair(N - 1 - row, col);
        };

        unordered_set<int> visited;
        queue<int> neighbor;
        neighbor.emplace(1);
        visited.emplace(1);

        int step = 0;
        while (!neighbor.empty()) {
            int n = neighbor.size();
            while (n) {
                int curr = neighbor.front();
                neighbor.pop();

                for (int i = 1; i <= 6; ++i) {
                    int next = curr + i;
                    if (next > id_max) {
                        break;
                    }

                    auto &&[pos_i, pos_j] = getPosById(next);
                    if (board[pos_i][pos_j] != -1) {
                        next = board[pos_i][pos_j];
                    }
                    if (next == id_max) {
                        return step + 1;
                    }
                    // cout << pos_i << " "<<pos_j <<" "<< next << endl;

                    if (visited.find(next) == visited.end()) {
                        neighbor.emplace(next);
                        visited.emplace(next);
                    }
                }
                n--;
            }
            step++;
        }

        return -1;
    }
};