class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();

        string res = s;
        int K_count = 0;
        auto reverseStrByRange = [&](int left) {
            int begin = left;
            int end = left + k - 1;

            if (K_count % 2 == 1) {
                return;
            }

            if (left + k > n) {
                end = n - 1;
            }

            while (begin < end) {
                std::swap(res[begin], res[end]);
                begin++;
                end--;
            }
        };

        for (int i = 0; i < n; i += k) {
            reverseStrByRange(i);
            K_count++;
        }

        return res;
    }
};