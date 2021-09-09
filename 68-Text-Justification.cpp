class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int width = 0;
        int left = 0;
        int right = 0;

        while (right < n) {
            int sz = words[right].size();
            if (width + sz + (right - left) <= maxWidth) {
                width += sz;
                right++;

                if (right == n) {
                    string s = make_sentence(words, left, right, " ");
                    res.emplace_back(s + blank(maxWidth - s.size()));
                    return res;
                    ;
                }
            } else {
                int word_num = right - left;
                int space_num = maxWidth - width;
                // 只有一行
                if (word_num == 1) {
                    res.emplace_back(words[left] + blank(space_num));
                } else {
                    int avg_space_num = space_num / (word_num - 1);
                    int extra_space_num = space_num % (word_num - 1);

                    string s1 =
                        make_sentence(words, left, left + extra_space_num + 1,
                                      blank(avg_space_num + 1));
                    string s2 = make_sentence(words, left + extra_space_num + 1,
                                              right, blank(avg_space_num));
                    res.emplace_back(s1 + blank(avg_space_num) + s2);
                }
                left = right;
                width = 0;
            }
        }

        return res;
    }

    string blank(int num) { return string(num, ' '); }

    string make_sentence(const vector<string> &words, int left, int right,
                         const string &sep) {
        string res = words[left];
        for (int i = left + 1; i < right; ++i) {
            res += sep + words[i];
        }
        return res;
    }
};