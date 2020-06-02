class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        auto sz = arr.size();
        if( sz == 1) return 1;
        map<int, int> dp;
        for(auto & val : arr) {
            dp[val] = 1;
            auto iter = dp.find(val - difference);
            if (iter != dp.end()) {
                dp[val] = iter->second + 1;
            }
        }
        auto ret = max_element(dp.begin(), dp.end(), [](const pair<int,int>& p1, 
        const pair<int,int>& p2){
            return p1.second < p2.second;
        });
        return ret->second;
    }
};