class Solution {
public:
    bool validTicTacToe(vector<string> &board) {
        int nx = 0;
        int no = 0;
        for (auto &str : board) {
            for (auto c : str) {
                if (c == 'X') {
                    nx++;
                } else if (c == 'O') {
                    no++;
                }
            }
        }

        auto win = [&board](char c) {
            for (int i = 0; i < 3; i++) {
                if (c == board[i][0] && c == board[i][1] && c == board[i][2]) {
                    return true;
                }
                if (c == board[0][i] && c == board[1][i] && c == board[2][i]) {
                    return true;
                }
            }

            if (c == board[0][0] && c == board[1][1] && c == board[2][2]) {
                return true;
            }
            if (c == board[0][2] && c == board[1][1] && c == board[2][0]) {
                return true;
            }
            return false;
        };
        // 轮流
        if (no != nx && no != nx - 1) {
            return false;
        }
        // X win
        if (win('X') && no != nx - 1) {
            return false;
        }
        // O win
        if (win('O') && no != nx) {
            return false;
        }

        return true;
    }
};