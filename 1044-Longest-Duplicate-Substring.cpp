class Solution {
public:
    string longestDupSubstring(string s) {
        constexpr int prime = 31;
        int n = s.size();
        int left = 0;
        int right = n;

        int len = 0;
        int pos = -1;

        auto find = [&](int len) {
            uint64_t hash = 0;
            uint64_t power = 1;

            for (int i = 0; i < len; i++) {
                hash = (hash * prime) + (s[i] - 'a');
                power *= prime;
            }

            unordered_set<uint64_t> exits{hash};

            for (int i = len; i < n; i++) {
                hash = hash * prime - power * (s[i - len] - 'a') + (s[i] - 'a');
                if (exits.count(hash)) {
                    return (i - len + 1);
                }
                exits.insert(hash);
            }

            return -1;
        };

        while (left < right) {
            int mid = (right - left) / 2 + left;
            int start = find(mid);
            if (start != -1) {
                len = mid;
                pos = start;
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        // cout << pos << " " << len<<endl;
        if (pos == -1) {
            return "";
        } else {
            return s.substr(pos, len);
        }
    }
};