class Solution {
public:
    int compress(vector<char> &chars) {
        int n = chars.size();

        int left = 1;
        char curr_char = chars[0];
        int count = 1;

        for (int i = 1; i < n; ++i) {
            if (chars[i] != curr_char) {
                if (count > 1) {
                    string s = to_string(count);
                    for (auto c : s) {
                        chars[left++] = c;
                    }
                }
                chars[left++] = chars[i];
                curr_char = chars[i];
                count = 1;
            } else {
                count++;
            }
        }
        if (count > 1) {
            string s = to_string(count);
            for (auto c : s) {
                chars[left++] = c;
            }
        }
        return left;
    }
};