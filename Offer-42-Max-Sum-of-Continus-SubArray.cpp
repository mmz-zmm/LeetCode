class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int res = -101;
        int sum = 0;
        for (auto num : nums) {
            if (sum < 0) {
                sum = 0;
            }
            sum += num;
            res = max(res, sum);
            // cout << res << " "<<sum<<endl;
        }
        return res;
    }
};