class Solution {
public:
    // 投票算法：让不同的两个元素相互抵消，最终余下的就可能是占比最高的元素。
    // candidate不一定是占比最高的元素，因为假设A有n个，B有n个，C有1个，A与B恰好还是互相抵消，C当选，但明显不是占比最高的元素
    // 因此，需要二次遍历数组，数一下其占比是否超过一半，再做判断
    int majorityElement(vector<int> &nums) {
        int candidate = 0;
        int count = 0;
        for (auto num : nums) {
            if (count == 0) {
                candidate = num;
                count++;
            } else {
                if (num == candidate) {
                    count++;
                } else {
                    count--;
                }
            }
        }

        auto candidate_num =
            count_if(nums.begin(), nums.end(),
                     [&candidate](int num) { return num == candidate; });

        return (candidate_num > (nums.size() / 2)) ? candidate : -1;
    }
};