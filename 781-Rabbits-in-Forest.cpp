/**
 *  根据题意，假设回答为k的兔子有n只，而实际上回答为k的同种颜色的兔子最多为(k+1)只，其余的回答为k
 * 的兔子一定是不同的颜色。因此回答为k的兔子的颜色有color=ceil(n/(k+1))种，总的兔子数为color *(k + 1)。
*/
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        if(answers.empty()) {
            return 0;
        }
        unordered_map<int, int> stat;
        for(auto answer : answers) {
            stat[answer]++;
        }
        //int color_num = 0;
        int rabbit_num = 0;
        int color_num_tmp = 0;
        for(const auto &[key, val] : stat) {
            color_num_tmp = ceil(val * 1.0 / (key + 1));

            //color_num += color_num_tmp;
            rabbit_num += color_num_tmp *(key + 1);
        }
        return rabbit_num;
    }
};