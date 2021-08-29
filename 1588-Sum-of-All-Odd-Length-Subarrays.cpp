class Solution {
public:
    int sumOddLengthSubarrays(vector<int> &arr) {
        int n = arr.size();
        int res = 0;

        vector<int> perfix_sum(n + 1);
        for (int i = 1; i <= n; ++i) {
            res += arr[i - 1];
            perfix_sum[i] = perfix_sum[i - 1] + arr[i - 1];
        }
        // cout << perfix_sum[n];

        for (int interval = 3; interval <= n; interval += 2) {
            int left_idx = 0;
            int right_idx = interval;
            while (right_idx <= n) {
                res += (perfix_sum[right_idx] - perfix_sum[left_idx]);
                left_idx++;
                right_idx++;
            }
        }

        return res;
    }
};