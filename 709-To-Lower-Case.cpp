class Solution {
public:
    string toLowerCase(string s) {
        constexpr int interval = 'A' - 'a';
        for (auto &c : s) {
            if (c >= 'A' && c <= 'Z') {
                c = c - interval;
            }
        }
        return s;
    }
};