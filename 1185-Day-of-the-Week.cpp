class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        auto isLeap = [](int year) {
            return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        };
        int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        vector<string> literal = {"Monday", "Tuesday",  "Wednesday", "Thursday",
                                  "Friday", "Saturday", "Sunday"};

        int days = 0;

        days = 365 * (year - 1971) + (year - 1 - 1968) / 4;

        for (int i = 1; i < month; i++) {
            days += months[i];
            if (i == 2 && isLeap(year)) {
                days += 1;
            }
        }
        days += day;

        return literal[(days + 3) % 7];
    }
};