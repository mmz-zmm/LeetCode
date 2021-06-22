class Solution {
public:
    vector<string> permutation(string s) {
        int n = s.size();

        set<string> res_set;
        vector<string> res;
        vector<int> visited(n);

        string str;

        backtrace(visited, s, str, res_set);

        for (auto &it : res_set) {
            res.emplace_back(it);
        }

        return res;
    }

    void backtrace(vector<int> &visited, const string &s, string &str,
                   set<string> &res_set) {
        if (str.size() == visited.size()) {
            res_set.emplace(str);
            return;
        }

        for (int i = 0; i < visited.size(); ++i) {
            if (!visited[i]) {
                visited[i] = 1;
                str.push_back(s[i]);
                backtrace(visited, s, str, res_set);
                visited[i] = 0;
                str.pop_back();
            }
        }
    }
};

class Solution2 {
public:
    vector<string> permutation(string s) {
        int n = s.size();

        vector<string> res;

        vector<int> visited(n);

        string str;
        str.reserve(n);

        // 让重复的元素聚集到一起
        sort(s.begin(), s.end());

        backtrace(visited, s, str, res);

        return res;
    }

    void backtrace(vector<int> &visited, const string &s, string &str,
                   vector<string> &res) {
        if (str.size() == visited.size()) {
            res.emplace_back(str);
            return;
        }

        for (int i = 0; i < visited.size(); ++i) {
            // 剪枝去重，以aab为例，只保留第一次(visited为[1,1,0])，后面的可能为[0,1,1]都剪掉
            if (i > 0 && !visited[i - 1] && (s[i - 1] == s[i])) {
                continue;
            }
            if (!visited[i]) {
                visited[i] = 1;
                str.push_back(s[i]);
                backtrace(visited, s, str, res);
                visited[i] = 0;
                str.pop_back();
            }
        }
    }
};

class Solution3 {
public:
    vector<string> permutation(string s) {
        int n = s.size();

        vector<string> res;

        vector<int> visited(n);

        string str;
        str.reserve(n);

        sort(s.begin(), s.end());

        function<void(int)> backtrace = [&](int cnt) {
            if (cnt == visited.size()) {
                res.emplace_back(str);
                return;
            }
            for (int i = 0; i < visited.size(); ++i) {
                // 剪枝去重，以aab为例，只保留第一次(visited为[1,1,0])，后面的可能为[0,1,1]都剪掉
                if (i > 0 && !visited[i - 1] && (s[i - 1] == s[i])) {
                    continue;
                }
                if (!visited[i]) {
                    visited[i] = 1;
                    str.push_back(s[i]);
                    backtrace(cnt + 1);
                    visited[i] = 0;
                    str.pop_back();
                }
            }
        };

        backtrace(0);

        return res;
    }
};