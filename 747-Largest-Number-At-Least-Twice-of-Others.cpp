class Solution {
public:
    int dominantIndex(vector<int> &nums) {
        vector<int> bucket(101, -1);
        int n = nums.size();

        if (n == 1) {
            return 0;
        }

        for (int i = 0; i < n; ++i) {
            bucket[nums[i]] = i;
        }

        int first = -1;
        int second = -1;
        for (int i = 100; i >= 0; i--) {
            if (bucket[i] != -1) {
                if (first == -1) {
                    first = bucket[i];
                    continue;
                }

                if (first != -1 && second == -1) {
                    second = bucket[i];
                    break;
                }
            }
        }
        return (nums[first] >= 2 * nums[second]) ? first : -1;
    }
};