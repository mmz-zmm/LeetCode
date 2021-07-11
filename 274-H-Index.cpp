class Solution {
public:
    int hIndex(vector<int> &citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();

        int left = 0;
        int right = n;
        int mid = 0;

        while (left < right) {
            mid = left + (right - left) / 2;
            if (citations[mid] >= n - mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return n - left;
    }
};