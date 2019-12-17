class Solution {
public:
    int direc[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    void solve(vector<vector<char>>& board) {
        if( board.empty() || board[0].empty())
            return;

        auto row = board.size();
        auto col = board[0].size();

        for(auto j = 0; j < col; ++j)
        {
            if(board[0][j] == 'O')  // first row
            {
                dfs(board,0,j);
            }
            if(board[row-1][j] == 'O') // last row
            {
                dfs(board,row-1,j);
            }
        }

        for(auto i = 0; i < row; ++i)
        {
            if(board[i][0] == 'O') // first column
            {
                dfs(board, i, 0);
            }

            if(board[i][col-1] == 'O') // last column
            {
                dfs(board, i, col-1);
            }
        }

        for(auto i = 0; i < row; ++i)
        {
            for( auto j = 0; j < col; ++j)
            {
                if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                if(board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
            }
        } 
    }

    void dfs(vector<vector<char>>& board, int row, int col)
    {
        board[row][col] = '#';
        int temp_row;
        int temp_col;
        for(auto i = 0; i < 4;++i)
        {
            temp_row = row + direc[i][0];
            temp_col = col + direc[i][1];

            if((1 <= temp_row && temp_row < board.size())
               && (1 <= temp_col && temp_col < board[0].size()) 
               && board[temp_row][temp_col] == 'O')
               {
                   dfs(board, temp_row, temp_col);
               }
        }

    }
};