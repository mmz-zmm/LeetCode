class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();

        vector<int> dot_pos;
        vector<int> e_pos;

        char c = 0;
        for (int i = 0; i < n; ++i) {
            c = s[i];
            if (c < '0' || c > '9') {
                if (c == '+' || c == '-') {
                    continue;
                } else if (c == '.') {
                    dot_pos.push_back(i);
                } else if (c == 'e' || c == 'E') {
                    e_pos.push_back(i);
                } else {
                    return false;
                }
            }
        }

        if (e_pos.empty()) {
            if (dot_pos.empty()) {
                return isInterger(s, 0, n - 1);
            } else if (dot_pos.size() == 1) {
                return isFloat(s, 0, n - 1, dot_pos[0]);
            } else {
                return false;
            }
        } else if (e_pos.size() == 1) {
            if (dot_pos.empty()) {
                return isInterger(s, 0, e_pos[0] - 1) &&
                       isInterger(s, e_pos[0] + 1, n - 1);
            } else if (dot_pos.size() == 1) {
                return dot_pos[0] < e_pos[0] &&
                       isFloat(s, 0, e_pos[0] - 1, dot_pos[0]) &&
                       isInterger(s, e_pos[0] + 1, n - 1);
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    bool isFloat(const string &s, int left, int right, int dot) {
        if (s[left] == '+' || s[left] == '-') {
            left++;
        }

        if (dot == left) {
            return isUnsignedInterger(s, left + 1, right);
        } else if (dot == right) {
            return isUnsignedInterger(s, left, right - 1);
        } else if (dot > left && dot < right) {
            return isUnsignedInterger(s, left, dot - 1) &&
                   isUnsignedInterger(s, dot + 1, right);
        } else {
            return false;
        }
    }
    bool isInterger(const string &s, int left, int right) {
        if (s[left] == '+' || s[left] == '-') {
            left++;
        }
        return isUnsignedInterger(s, left, right);
    }

    bool isUnsignedInterger(const string &s, int left, int right) {
        if (left > right) {
            return false;
        }
        while (left <= right) {
            if (s[left] < '0' || s[left] > '9') {
                return false;
            }
            left++;
        }
        return true;
    }
};