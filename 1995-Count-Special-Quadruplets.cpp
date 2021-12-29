class Solution {
public:
    int countQuadruplets(vector<int> &nums) {
        int n = nums.size();
        vector<int> bucket(101);

        int res = 0;

        for (int c = n - 2; c >= 2; c--) {
            bucket[nums[c + 1]]++;
            for (int b = c - 1; b >= 1; b--) {
                for (int a = b - 1; a >= 0; a--) {
                    int sum = nums[a] + nums[b] + nums[c];
                    if (sum <= 100 && bucket[sum]) {
                        // cout << nums[a] << " "<<nums[b]<<" "<<nums[c]<<" "<<
                        // sum <<endl;
                        res += bucket[sum];
                    }
                }
            }
        }
        return res;
    }
};