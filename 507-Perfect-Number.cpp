class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) {
            return false;
        }

        int half = sqrt(num);
        set<int> res;
        res.insert(1);
        for (int i = 2; i <= half; i++) {
            int extra = num % i;
            if (!extra) {
                res.insert(i);
                res.insert(num / i);
            }
        }

        return accumulate(res.begin(), res.end(), 0) == num;
    }
};