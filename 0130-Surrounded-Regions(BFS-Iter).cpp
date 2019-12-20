class Solution {
public:
    int direc[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    struct Node{
        Node(int x, int y):x_(x),y_(y){}
        int x_;
        int y_;
    };
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty())
            return ;
        
        auto row = board.size();
        auto col = board[0].size();

        for(auto j = 0; j < col; ++j)
        {
            if(board[0][j] == 'O')
                bfs(board, 0, j);
            
            if(board[row-1][j] == 'O')
                bfs(board, row-1, j);
        }

        for(auto i = 0; i < row; ++i)
        {
            if(board[i][0] == 'O')
                bfs(board, i, 0);

            if(board[i][col-1] == 'O')
                bfs(board, i, col-1);
        }
        
        for(auto i = 0; i < row; ++i)
        {
            for(auto j=0; j < col; ++j)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }

    void bfs(vector<vector<char>> & board, int row, int col)
    {
        queue<Node> q;
        q.push(Node(row, col));
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            if( node.x_>=0 && node.x_< board.size() &&
                node.y_>=0 && node.y_< board[0].size() &&
                board[node.x_][node.y_] == 'O')
                {
                    board[node.x_][node.y_] = '#';
                    for(auto i = 0; i < 4; ++i)
                    {
                        q.push(Node(node.x_ + direc[i][0], node.y_ + direc[i][1]));
                    }
                }
        }
        
    }
};