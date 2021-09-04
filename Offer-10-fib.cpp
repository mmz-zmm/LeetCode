class Solution {
public:
    int fib(int n) {
        if( n < 2) {
            return n;
        }
        int fn_1 = 1;
        int fn_2 = 0;
        int fn = 0;
        constexpr int MOD = 1'000'000'007;

        for(int i = 2; i <= n; ++i) {
            fn = (fn_1 + fn_2 ) % MOD;
            fn_2 = fn_1;
            fn_1 = fn;
        }

        return fn;
    }
};