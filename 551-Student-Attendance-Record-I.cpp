class Solution {
public:
    bool checkRecord(string s) {
        bool absent = false;
        int absent_cnt = 0;
        bool late = false;
        int late_cnt = 0;
        for (auto c : s) {
            if (c == 'A') {
                absent_cnt++;
                late_cnt = 0;
                if (absent_cnt >= 2) {
                    return false;
                }
            } else if (c == 'L') {
                if (late_cnt == 2) {
                    return false;
                } else {
                    late_cnt++;
                }
            } else {
                late_cnt = 0;
            }
        }

        return true;
    }
};