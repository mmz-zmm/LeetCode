class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        auto level = 0;
        auto label_bk = label;
        // 获取当前数字在第几层
        while(label_bk) {
            level++;
            label_bk >>= 1;
        }

        vector<int> res(level);
        res[level - 1] = label; // 最后一行
        res[0] = 1;
        /*
        每一行的最小值为2^(n - 1) + 1，最大值为2^(n) - 1，因为是之字形，
        待求值与正常父节点(lebel / 2 )关于二叉树中轴对称，因为是递增数列， 
        level_max + level_min = const, 我们使用const - label/2便可得到目标值，无论是
        奇数行还是偶数行
        */  
        for(auto i = level - 1; i > 1; --i ) {
            auto base = pow(2, i);
            auto level_sum = (base - 1) + (base / 2);
            res[i - 1] = level_sum - res[i] /2;
        }
        return res;
    }
};
