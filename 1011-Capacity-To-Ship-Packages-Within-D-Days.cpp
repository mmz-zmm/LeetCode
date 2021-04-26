class Solution {
public:
    int shipWithinDays(vector<int> &weights, int D) {
        int left = 0;
        int right = 0;
        for (auto &weight : weights) {
            left = max(left, weight);
            right += weight;
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (satisfy(weights, mid, D)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    bool satisfy(const vector<int> &weights, int capacity, int D) {
        int day = 0;
        int total = 0;
        for (auto &w : weights) {
            if (total + w > capacity) {
                day++;
                total = 0;
            }
            total += w;
            if (day > D) {
                return false;
            }
        }
        day += 1; //最后一批

        return day <= D;
    }
};