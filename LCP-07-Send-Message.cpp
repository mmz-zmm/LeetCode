class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {

        unordered_map<int, vector<int>> relation_map;
        for(auto & item : relation) {
            relation_map[item[0]].push_back(item[1]);
        }

        queue<int> neighbor;
        neighbor.emplace(0);
        while(k--) {
            int n = neighbor.size();
            while(n--) {
                int front = neighbor.front();
                neighbor.pop();
                for(auto item: relation_map[front]) {
                    neighbor.emplace(item);
                }
            }
        }

        int res = 0;
        while(!neighbor.empty()){
            int front = neighbor.front();
            neighbor.pop();
            if(front == n -1) {
                res++;
            }
        }
        return res;
    }
};