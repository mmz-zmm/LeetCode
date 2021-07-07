class Solution {
public:
    int countPairs(vector<int> &deliciousness) {

        const int mod = 1000000000 + 7;
        unordered_map<int, int> index;

        int res = 0;
        for (auto meal : deliciousness) {
            for (int i = 0; i < 22; ++i) {
                int target = (1 << i) - meal;
                int count = index.count(target) ? index[target] : 0;
                res = (res + count) % mod;
            }
            index[meal]++;
        }

        return res;
    }
};