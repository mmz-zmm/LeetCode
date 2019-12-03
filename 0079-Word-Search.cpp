class Solution {
public:
    int d[4][2] ={{0,-1},{-1,0},{0,1},{1,0}};
    int row;
    int col;

    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || word.size() == 0)
        {
            return false;
        }

        row = board.size();
        col = board[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));

        for(auto i = 0; i < row; ++i)
        {
            for( auto j = 0; j < col; ++j)
            {
                if(backtrace(board, visited, i, j, word, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool backtrace(const vector<vector<char>> &board, vector<vector<int>> & visited, int row_, int col_, const string & word, int curr)
    {
        if(curr == word.size() - 1)
            return board[row_][col_] == word[curr];

        if(board[row_][col_] == word[curr])
        {
            visited[row_][col_] = 1;
            for(auto i = 0; i < 4; ++i)
            {
                int new_row = row_ + d[i][0];
                int new_col = col_ + d[i][1];
                if(legal(new_row, new_col) && !visited[new_row][new_col] &&
                 backtrace(board, visited, new_row, new_col, word, curr+1))
                 {
                     return true;
                 }
            }
            visited[row_][col_] = 0;
        }

        return false;
    }

    bool legal(int row_, int col_)
    {
        return row_ >=0 && row_ < row && col_ >=0 && col_ < col;
    }
};