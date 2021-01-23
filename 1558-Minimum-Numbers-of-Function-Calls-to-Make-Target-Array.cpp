// 贪心算法：优先使用“乘2“操作，最后使用“加1“操作
// 对于任意一个数字，可以通过查看其二进制的方式分解为以上两个操作
// 例如5, 其2进制为101，其中每一位1都是通过”加1”操作获取的，而“从最左侧1开始往后的位数“，则代表了”乘2”操作的次数
//     0 加1 -> 1
//     1 左移2位 -> 100
//    100 加1 -> 101
// 对于数组来说，由于”乘2”是公共操作，“加1“是单独操作，因此我们将公共的”乘2”操作次数 + 所有元素的“加1“操作次数， 
// 便得到最优的变换次数。
// 而公共的”乘2”次数，实际上取决于数组中最大元素所需的“乘2“次数（为什么呢？因为其他元素可以通过初始值0*2来跳过不需要的”乘2“操作 ）
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int multBy2Op = 0;
        int addBy1Op = 0;
        int zeros = 0;
        int ones = 0;
        for( auto num : nums) {
            getBitInfo(num, zeros, ones);
            multBy2Op = max(multBy2Op, zeros + ones - 1);
            addBy1Op += ones;
        }
        return addBy1Op + multBy2Op;
    }

    void getBitInfo(int val, int &zeros, int &ones) {
        zeros = 0;
        ones = 0;
        while(val) {
            if(val & 1) {
                ones += 1;
            } else {
                zeros += 1;
            }
            val >>= 1;
        }
    }
};