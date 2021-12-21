class Solution {
public:
    int dayOfYear(string date) {
        vector<int> months = {0,  31, 28, 31, 30, 31, 30,
                              31, 31, 30, 31, 30, 31};
        auto isLeap = [](int year) {
            return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
        };

        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        return accumulate(months.begin(), months.begin() + month, 0) +
               (month > 2 && isLeap(year) ? 1 : 0) + day;
    }
};