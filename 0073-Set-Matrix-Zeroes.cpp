class Solution {
public:
    /*使用第1行第1列来作为额外的空间来保存这样一个信息：第i行是否要为0，第j列是否有为零*/
    void setZeroes(vector<vector<int>>& matrix) {
        //先记录下”第一行和第一列是否全是0“这样的一个数据，否则会因为后续对第一行第一列的更新造成数据丢失
        bool first_row = false;
        bool first_column = false;

        // 将行列为0的信息保存下来
        for(auto i = 0; i < matrix.size(); ++i)
        {
            for(auto j = 0; j < matrix[0].size(); ++j)
            {
                auto val = matrix[i][j];
                if(val == 0)
                {
                    if( i == 0)
                    {
                        first_row = true;
                    }

                    if( j == 0)
                    {
                        first_column = true;
                    }
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // 根据信息将[2,m]行,[2,n]列进行清零
        for(auto i = 1; i < matrix.size(); ++i)
        {
            for(auto j = 1; j < matrix[0].size(); ++j)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
                
            }
        }

        // 最后处理第1行与第1列
        if(first_column)
        {
            for(auto i = 0; i < matrix.size(); ++i)
            {
                matrix[i][0] = 0;
            }
        }

        if(first_row)
        {
            for(auto j = 0; j < matrix[0].size(); ++j)
            {
                matrix[0][j] = 0;
            }
        }
    }
};