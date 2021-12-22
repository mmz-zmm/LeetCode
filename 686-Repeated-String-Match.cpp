class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s = a;
        while (s.size() <= b.size()) {
            s += a;
        }
        s += a;

        auto pos = s.find(b);
        if (pos == string::npos) {
            return -1;
        }

        return (pos + b.size() - 1) / a.size() + 1;
    }
};