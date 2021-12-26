class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        stringstream ss(text);
        vector<string> text_vec;
        string s;
        while (ss >> s) {
            text_vec.emplace_back(s);
        }

        int n = text_vec.size();

        vector<string> res;
        for (int i = 0; i < n - 2; i++) {
            if (text_vec[i] == first && text_vec[i + 1] == second) {
                res.emplace_back(text_vec[i + 2]);
            }
        }

        return res;
    }
};