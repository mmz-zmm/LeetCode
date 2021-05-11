class Solution {
public:
    // 前n个正整数的排列，说明了其范围为[1, n]，这一点非常关键，结合first_expt，便可以得到第一个元素，
    // 有第一个元素后，利用encoded便可以得到perm
    vector<int> decode(vector<int> &encoded) {
        int n = encoded.size() + 1;
        // total = a1 ^ a2 .. an
        int total = 0;
        for (int i = 1; i <= n; ++i) {
            total ^= i;
        }
        // first_expt = a2 ^ a3 ^ a4 ... an
        // encoded[0] = a1 ^ a2
        // encoded[1] = a2 ^ a3
        // encoded[2] = a3 ^ a4
        // encoded[4] = a4 ^ a5
        int first_expt = 0;
        for (int i = 1; i < encoded.size(); i += 2) {
            first_expt ^= encoded[i];
        }

        vector<int> perm(n);
        perm[0] = total ^ first_expt;
        for (int i = 0; i < encoded.size(); ++i) {
            perm[i + 1] = perm[i] ^ encoded[i];
        }

        return perm;
    }
};