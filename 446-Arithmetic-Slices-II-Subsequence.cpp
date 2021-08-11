class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        int res = 0;

        int n = nums.size();

        vector<unordered_map<int64_t, int>> f(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int64_t d = static_cast<int64_t>(nums[i]) - nums[j];
                auto it = f[j].find(d);
                int cnt = (it == f[j].end() ? 0 : it->second);
                // cout << i << " "<< j <<" "<< d << " "<< cnt <<endl;
                res += cnt;
                f[i][d] += (cnt + 1);
            }
        }
        return res;
    }
};