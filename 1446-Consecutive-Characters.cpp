class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        char prev = '0';
        int max_len = 0;
        int len = 1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == prev) {
                len++;
            } else {
                len = 1;
                prev = s[i];
            }
            max_len = max(max_len, len);
        }
        return max_len;
    }
};