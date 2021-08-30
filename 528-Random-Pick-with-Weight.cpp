class Solution {
public:
    Solution(vector<int> &w) : gen(random_device{}()) {
        int n = w.size();
        prefix_sum.reserve(n);

        partial_sum(w.begin(), w.end(), back_inserter(prefix_sum));
        dis = uniform_int_distribution<int>(1, prefix_sum[n - 1]);
    }

    int pickIndex() {
        int pick = dis(gen);
        auto iter = lower_bound(prefix_sum.begin(), prefix_sum.end(), pick);

        return distance(prefix_sum.begin(), iter);
    }

    vector<int> prefix_sum;
    mt19937 gen;
    uniform_int_distribution<> dis;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */