class Solution {
public:
    int peakIndexInMountainArray(vector<int> &arr) {
        int sz = arr.size();
        int left = 0;
        int right = sz - 1;
        int mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};