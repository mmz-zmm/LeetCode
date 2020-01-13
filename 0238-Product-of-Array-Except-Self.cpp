class Solution {
public:
    // 使用一个数组，首先从左到右计算前缀积（不包含当前元素），随后从右往左计算后缀积；
    // 对应位置的前缀积与后缀积的乘积就是所求的结果
    vector<int> productExceptSelf(vector<int>& nums) {
        size_t size = nums.size();
        if (size == 0) return {};
        vector<int> ret(size);
        // prefix multiply
        ret[0] = 1;
        for (int i = 1; i < size; ++i) {
            ret[i] = ret[i-1] * nums[i-1];
        }
        // suffix multiply
        int suffix = 1;
        for (int i = size - 1; i >= 0; --i) {
            ret[i] = ret[i] * suffix;
            suffix *= nums[i];
        }
        return ret;
    }
};