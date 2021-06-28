class Solution {
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source,
                              int target) {
        if (source == target) {
            return 0;
        }
        unordered_map<int, vector<int>> route_map;
        for (int i = 0; i < routes.size(); ++i) {
            for (auto node : routes[i]) {
                route_map[node].push_back(i);
            }
        }

        unordered_set<int> visited;
        queue<int> path;
        path.emplace(source);

        int step = 0;
        while (!path.empty()) {
            int n = path.size();
            while (n) {
                int node_1 = path.front();
                path.pop();
                // cout << node_1 << "-";
                auto &lines_contain_node = route_map[node_1];
                for (auto line : lines_contain_node) {
                    if (visited.find(line) == visited.end()) {
                        for (auto node : routes[line]) {
                            // cout << node <<" ";
                            if (node == target) {
                                return step + 1;
                            }
                            path.emplace(node);
                        }
                        visited.emplace(line);
                    }
                }
                // cout << endl;
                n--;
            }
            step++;
        }
        return -1;
    }
};