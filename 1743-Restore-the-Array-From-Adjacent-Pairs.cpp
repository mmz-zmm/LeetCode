class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> maps;
        int first = 0;
        int second = 0;
        for(auto & pairs : adjacentPairs) {
            first = pairs[0];
            second = pairs[1];
            maps[first].push_back(second);
            maps[second].push_back(first);
        }

        auto iter = find_if(maps.begin(), maps.end(), [](const pair<int, vector<int>> & adjacent){
            return  adjacent.second.size() == 1;
        });

        vector<int> res;
        res.reserve(adjacentPairs.size() + 1);
        int prev = iter->first;
        res.push_back(prev);
        int curr = iter->second[0];
        
        while(maps[curr].size() == 2) {
            res.push_back(curr);
            for(auto ele:  maps[curr]) {
                if(ele  !=  prev) {
                    prev = curr;
                    curr = ele;
                    break;
                }
            }     
        }

        if(maps[curr].size()  == 1) {
            res.push_back(curr);
        }

        return res;
    }
};