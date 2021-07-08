class Solution {
public:
    int numSubarraysWithSum(vector<int> &nums, int goal) {
        int sum = 0;
        for (auto &num : nums) {
            sum += num;
            num = sum;
        }
        unordered_map<int, int> ump;
        ump.emplace(0, 1); // 前缀和为0的项数目为1
        int target = 0;
        int cnt = 0;
        for (auto partialSum : nums) {
            // cout << partialSum << " ";
            int target = partialSum - goal;
            cnt += (ump.count(target) ? ump[target] : 0);
            ump[partialSum]++;
        }

        return cnt;
    }
};