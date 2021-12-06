class Solution {
public:
    string truncateSentence(string s, int k) {
        int count = 0;
        int n = s.size();
        int pos = n;
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                count++;
                if (count == k) {
                    pos = i;
                    break;
                }
            }
        }
        return s.substr(0, pos);
    }
};