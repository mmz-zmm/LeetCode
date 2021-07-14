class Solution {
public:
    int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2) {
        set<int> nums1_set(nums1.begin(), nums1.end());

        auto getAbs = [](int a, int b) -> int {
            return a >= b ? a - b : b - a;
        };

        const int mod = 1000000007;
        int n = nums1.size();

        int reduce = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int old = getAbs(nums1[i], nums2[i]);
            // cout << old <<endl;
            if (old == 0) {
                continue;
            }
            res = (res + old) % mod;
            // higher
            auto iter = nums1_set.lower_bound(nums2[i]);
            if (iter != nums1_set.end()) {
                int new1 = getAbs(*iter, nums2[i]);
                reduce = min(reduce, -old + new1);
            }
            // lower
            if (iter != nums1_set.begin()) {
                int new2 = getAbs(*(--iter), nums2[i]);
                reduce = min(reduce, -old + new2);
            }
            // cout << reduce <<endl;
        }

        return (res + reduce + mod) % mod;
    }
};