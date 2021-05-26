class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int> st;

        unordered_map<int, int> brace;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int j = st.top();
                brace[i] = j;
                brace[j] = i;
                st.pop();
            }
        }

        string res;
        res.reserve(n);
        int dir = 1;

        for (int i = 0; i < n; i += dir) {
            if (s[i] == '(' || s[i] == ')') {
                i = brace[i];
                dir = -dir;
            } else {
                res += s[i];
            }
        }
        return res;
    }
};