class Solution {
public:
    int superPow(int a, vector<int> &b) {
        int n = b.size();
        constexpr int mod = 1337;

        auto Pow = [&mod](int base, int exp) -> int {
            int res = 1;
            base %= mod;
            while (exp--) {
                res = (res * base) % mod;
            }
            return res;
        };

        vector<int> pow_bucket(10, 0);
        int res = Pow(a, b[0]);
        pow_bucket[b[0]] = res;
        int tmp = 0;
        for (int i = 1; i < n; ++i) {
            if (pow_bucket[b[i]]) {
                tmp = pow_bucket[b[i]];
            } else {
                tmp = Pow(a, b[i]);
                pow_bucket[b[i]] = tmp;
            }
            res = Pow(res, 10) * tmp;
            res %= mod;
        }

        return res;
    }
};