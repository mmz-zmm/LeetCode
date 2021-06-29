class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        int remainder = 0;
        while(columnNumber) {
            remainder = (columnNumber - 1) % 26 + 1;
            res.push_back(remainder - 1 + 'A');
            columnNumber =(columnNumber - remainder) / 26;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};