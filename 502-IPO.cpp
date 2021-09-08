class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits,
                             vector<int> &capital) {
        int n = capital.size();
        vector<pair<int, int>> index;
        index.reserve(n);

        for (int i = 0; i < n; ++i) {
            index.emplace_back(capital[i], profits[i]);
        }
        sort(index.begin(), index.end());

        priority_queue<int> pq;
        int curr = 0;
        for (int i = 0; i < k; ++i) {
            while (curr < n && index[curr].first <= w) {
                pq.push(index[curr].second);
                curr++;
            }

            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            } else {
                break;
            }
        }

        return w;
    }
};