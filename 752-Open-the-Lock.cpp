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

class Solution2 {
public:
    int openLock(vector<string> &deadends, string target) {
        if (target == "0000") {
            return 0;
        }
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.find("0000") != dead.end()) {
            return -1;
        }

        queue<string> headq;
        queue<string> tailq;
        unordered_map<string, int> head_s;
        unordered_map<string, int> tail_s;
        headq.emplace("0000");
        tailq.emplace(target);

        head_s["0000"] = 0;
        tail_s[target] = 0;

        int res = -1;
        while (!headq.empty() && !tailq.empty()) {

            if (headq.size() < tailq.size()) {
                res = bfs(headq, head_s, tail_s, dead);
            } else {
                res = bfs(tailq, tail_s, head_s, dead);
            }
            if (res != -1)
                return res;
        }
        return -1;
    }
    char next(char c) { return (c == '9') ? '0' : c + 1; }

    char prev(char c) { return (c == '0') ? '9' : c - 1; }

    int bfs(queue<string> &path, unordered_map<string, int> &my_judge,
            unordered_map<string, int> &other_judge,
            unordered_set<string> &dead) {
        string key = path.front();
        path.pop();
        int step = my_judge[key];

        char old;
        for (int i = 0; i < 4; i++) {
            old = key[i];
            for (int j = 0; j < 2; j++) {
                key[i] = (j == 0) ? next(old) : prev(old);
                if (dead.find(key) == dead.end() &&
                    my_judge.find(key) == my_judge.end()) {
                    auto iter = other_judge.find(key);
                    if (iter != other_judge.end()) {
                        return step + 1 + iter->second;
                    } else {
                        my_judge[key] = step + 1;
                        path.emplace(key);
                    }
                }
            }
            key[i] = old;
        }
        return -1;
    }
};