// 根据提示，给定某个体力消耗limit k, 使用DFS来寻找从左上角到右下角是否存在
// 满足条件的路，然后使用二分法来不断逼近k的最小值。
class Solution {
public:
    struct Pos {
        Pos(int i, int j) :i_(i), j_(j){}
        int i_;
        int j_;
    };


    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        if(row == 1 && col == 1) {
            return 0;
        }
        
        int maxHeight = 0;
        for(int i = 0; i < row; ++i)
        {
            maxHeight = max(maxHeight, *max_element(heights[i].begin(), heights[i].end()));
        }

        int left = 0;
        int right = maxHeight;

        while(left < right) {
            int mid = left + (right - left) / 2 ;
            if(dfs(heights, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            } 
        }
        return left;
    }

    int direc[4][2]= {{1,0},{0,1},{-1,0},{0,-1}};

    bool dfs(vector<vector<int>>& heights, int limit)
    {
        int row = heights.size();
        int col = heights[0].size();
        vector<Pos> trace;
        vector<vector<int>> visited(row , vector<int>(col, 0));
        
        trace.push_back(Pos(0,0));
        visited[0][0] = 1;

        auto predNodeInside = [row, col](int i, int j)->bool { 
            return (i >= 0 && i < row) && (j >=0 && j < col);
        };

        int next_row;
        int next_col;

        while(!trace.empty()) {
            auto node = trace.back();

            int i;
            for(i = 0; i < 4; ++i)
            {
                next_row = node.i_ + direc[i][0];
                next_col = node.j_ + direc[i][1];

                if(predNodeInside(next_row, next_col) 
                    && !visited[next_row][next_col]
                    && abs(heights[next_row][next_col] - heights[node.i_][node.j_]) <= limit)
                {
                    if(next_row == row - 1 && next_col == col - 1)
                    {
                        return true;
                    }
                    trace.push_back(Pos(next_row, next_col));
                    visited[next_row][next_col] = 1;
                    break;
                }
            }
            if(i == 4) {
                trace.pop_back();
            }
        }
        return false;
    }
    
};