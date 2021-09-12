class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftSt;
        stack<int> starSt;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                leftSt.push(i);
            } else if (s[i] == ')') {
                if (!leftSt.empty()) {
                    leftSt.pop();
                } else {
                    if (starSt.empty()) {
                        return false;
                    } else {
                        starSt.pop();
                    }
                }
            } else {
                starSt.push(i);
            }
        }

        while (!leftSt.empty() && !starSt.empty()) {
            if (leftSt.top() > starSt.top()) {
                return false;
            } else {
                leftSt.pop();
                starSt.pop();
            }
        }
        return starSt.size() >= leftSt.size();
    }
};
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftSt;
        stack<int> starSt;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                leftSt.push(i);
            } else if (s[i] == ')') {
                if (!leftSt.empty()) {
                    leftSt.pop();
                } else {
                    if (starSt.empty()) {
                        return false;
                    } else {
                        starSt.pop();
                    }
                }
            } else {
                starSt.push(i);
            }
        }

        while (!leftSt.empty() && !starSt.empty()) {
            if (leftSt.top() > starSt.top()) {
                return false;
            } else {
                leftSt.pop();
                starSt.pop();
            }
        }
        return starSt.size() >= leftSt.size();
    }
};