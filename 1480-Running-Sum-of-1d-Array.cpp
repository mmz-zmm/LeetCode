class Solution {
public:
    vector<int> runningSum(vector<int> &nums) {
        vector<int> res(nums);

        int n = nums.size();

        for (int i = 1; i < n; ++i) {
            res[i] += res[i - 1];
        }

        return res;
    }
};