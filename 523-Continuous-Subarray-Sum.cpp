class Solution {
public:
    // 前缀和+哈希表，如果两个数的差是k的倍数，则这两个数与k的余数必定相等，
    // 我们在hash表中记录当前的前缀和与k的余数以及当前的索引，随后遇到一个前缀和时，如果发现其余数
    // 已经存在，则表面已经有子数组的和是k的倍数，此时只需要满足子数组大小大于2即可。
    bool checkSubarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }

        unordered_map<int, int> remainder_pos;
        remainder_pos.emplace(0, -1);

        long long prefix = 0;
        int remainder = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefix += nums[i];
            remainder = prefix % k;
            auto it = remainder_pos.find(remainder);
            if (it != remainder_pos.end()) {
                if ((i - it->second) >= 2) {
                    return true;
                }
            } else {
                remainder_pos.emplace(remainder, i);
            }
        }
        return false;
    }
};