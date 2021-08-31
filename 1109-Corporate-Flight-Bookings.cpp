class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {

        vector<int> diff(n + 1);
        int start = 0;
        int end = 0;
        int seats = 0;
        for (auto &book : bookings) {
            start = book[0] - 1;
            end = book[1] - 1;
            seats = book[2];
            diff[start] += seats;
            diff[end + 1] -= seats;
        }

        vector<int> answer(n);
        answer[0] = diff[0];
        for (int i = 1; i < n; ++i) {
            answer[i] = answer[i - 1] + diff[i];
        }
        return answer;
    }
};