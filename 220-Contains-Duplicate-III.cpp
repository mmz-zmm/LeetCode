/** 对于num[i],先构造一个长度为k的set，里面存放的是nums[i]左侧的数据，
 * 在里面找到大于等于nums[i] - t的数，随后检查它是否小于nums[i] + t,
 * 如果符合，则满足要求。如不符合，移动窗口(insert)，同时窗口的大小(erase)
 * */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        set<long> s;
        for (int i = 0; i < nums.size(); ++i) {
            auto lower = s.lower_bound(static_cast<long>(nums[i]) - t);
            if (lower != s.end() && *lower <= static_cast<long>(nums[i]) + t) {
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