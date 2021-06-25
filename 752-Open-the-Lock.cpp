class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.find("0000") != dead.end()) {
            return -1;
        }
        queue<string> q;
        q.push("0000");
        dead.insert("0000");
        int level = 0;
        int step[] = {-1, 1};
        while (!q.empty()) {
            int n = q.size();
            while (n) {
                string &node = q.front();
                if (node == target) {
                    return level;
                }
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 2; ++j) {
                        int digit = ((node[i] - '0') + step[j] + 10) % 10;
                        string next = node;
                        next[i] = ('0' + digit);
                        if (dead.find(next) == dead.end()) {
                            dead.insert(next);
                            q.push(next);
                        }
                    }
                }
                q.pop();
                n--;
            }
            level++;
        }
        return -1;
    }
};