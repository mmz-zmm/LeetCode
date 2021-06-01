class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector<long long> candiesPrefixSum(n + 1);

        for(int i = 1; i <= n; ++i) {
            candiesPrefixSum[i] = candiesPrefixSum[i - 1] + candiesCount[i - 1];
        }

        vector<bool> res;
        res.reserve(queries.size());

        int type, day, cap;
        long long earliest, latest; // 注意为long long
        for(auto & query : queries) {
            type = query[0];
            day = query[1] + 1;
            cap = query[2];
            earliest = (candiesPrefixSum[type]) / cap + 1;
            latest = candiesPrefixSum[type + 1];

            if(day >= earliest && day <= latest) {
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }
        return res;
        
    }
};