class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> fre;
        for(auto c : s) {
            fre[c]++;
        }

        using elem_type = pair<char, int>;

        auto cmp = [](const pair<char, int>& lhs, const pair<char, int>& rhs) {
            return lhs.second < rhs.second;
        };

        priority_queue<elem_type, vector<elem_type>, decltype(cmp)> fre_pq(cmp);
        for(auto & item : fre) {
            fre_pq.emplace(std::move(item));
        }

        string res;
        while(!fre_pq.empty()) {
            auto  [c, num] = fre_pq.top();
            while(num--) {
                res += c;
            }
            fre_pq.pop();
        }

        return res;
    }
};