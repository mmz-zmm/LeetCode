class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> maga(26, 0);
        for (auto c : magazine) {
            maga[c - 'a']++;
        }

        for (auto c : ransomNote) {
            if (maga[c - 'a'] > 0) {
                maga[c - 'a']--;
            } else {
                return false;
            }
        }

        return true;
    }
};