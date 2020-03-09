class Solution {
public:
    // bucket sort
    vector<int> sortArray(vector<int>& nums) {
        vector<int> buckets(50000 * 2 + 1, 0);
        vector<int> ret(nums.size(), 0);

        for(auto num : nums) {
            buckets[50000 + num]++;
        }

        int j = 0;
        for(int i = 0; i < buckets.size(); ++i) {
            while( buckets[i]--) {
                ret[j++] = i - 50000;
            }
        }
        return ret;
    }
};
