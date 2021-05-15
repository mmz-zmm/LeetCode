class Solution {
public:
    int romanToInt(string s) {
        const pair<string, int> roman_code[] = {
            {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100},
            {"XC", 90},  {"L", 50},   {"XL", 40}, {"X", 10},   {"IX", 9},
            {"V", 5},    {"IV", 4},   {"I", 1},
        };

        int res = 0;
        int pos = 0;
        for (auto &[key, val] : roman_code) {
            while (startWith(s, pos, key)) {
                res += val;
                pos += key.size();
            }

            if (pos == s.size()) {
                break;
            }
        }
        return res;
    }

    bool startWith(const string &s, int begin, const string &target) {
        if (begin + target.size() > s.size()) {
            return false;
        }

        for (auto c : target) {
            if (s[begin++] != c) {
                return false;
            }
        }

        return true;
    }
};