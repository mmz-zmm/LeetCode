class Solution {
public:
    // 使用三个变量分别记录最小，次小和第三小
    bool increasingTriplet(vector<int>& nums) {
        if( nums.size() < 3) return false;
        int m1 = INT_MAX;
        int m2 = INT_MAX;
        for(const auto num : nums) {
            if(num <= m1) {
                m1 = num;
            } else if(num <= m2) {
                m2 = num;
            }
            else {
                return true;
            }
        }
        return false;
    }
};