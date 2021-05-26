class Solution {
public:
    int minChanges(vector<int> &nums, int k) {
        int n = nums.size();
        int max = 1024;
        vector<vector<int>> f(k, vector<int>(1024, INT_MAX));
        vector<int> g(k, INT_MAX);

        for (int i = 0; i < k; ++i) {
            int cnt = 0;
            unordered_map<int, int> map;
            for (int j = i; j < n; j += k) {
                map[num[j]]++;
                cnt++;
            }

            if (i == 0) {
                for (int xor = 0; xor < max; xor ++) {
                    f[0][xor] = min(f[0][xor], cnt - map[xor])
                }
            }
        }
    }
};