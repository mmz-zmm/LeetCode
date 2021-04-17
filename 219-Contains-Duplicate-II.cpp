class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            auto res = s.find(nums[i]);
            if (res != s.end()) {
                return true;
            }
            s.insert(nums[i]);
            if (i >= k) {
                s.erase(nums[i - k]);
            }
        }
        return false;
    }
};