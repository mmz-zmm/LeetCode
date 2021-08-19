class Solution {
public:
    string reverseVowels(string s) {

        int n = s.size();
        int left = 0;
        int right = s.size() - 1;

        string res = s;

        auto isVoewl = [](char c) {
            if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' ||
                c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U') {
                return true;
            }
            return false;
        };

        while (left < right) {
            while (left < right && !isVoewl(res[left])) {
                left++;
            }
            while (left < right && !isVoewl(res[right])) {
                right--;
            }
            std::swap(res[left], res[right]);
            left++;
            right--;
        }
        return res;
    }
};