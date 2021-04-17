class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        set<int> s;
        for (auto &num : nums) {
            if (s.count(num)) {
                return true;
            }
            s.insert(num);
        }
        return false;
    }
};