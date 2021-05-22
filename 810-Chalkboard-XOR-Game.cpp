class Solution {
public:
    // 数学问题，请参考题解：https://leetcode-cn.com/problems/chalkboard-xor-game/solution/hei-ban-yi-huo-you-xi-by-leetcode-soluti-eb0c/
    bool xorGame(vector<int> &nums) {
        return (nums.size() % 2 == 0) ||
               (accumulate(nums.begin(), nums.end(), 0, bit_xor<int>()) == 0);
    }
};