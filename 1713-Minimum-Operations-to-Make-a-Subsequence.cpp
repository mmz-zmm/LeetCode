class Solution {
public:
    // 问题的本质是求两个数组的最长公共子序列。
    // 利用target数组的非重复性，将值转化为下标的位置，这样一来，target为单调递增的序列，
    // 随后在arr中，将出现在target的数值转化为其下标，未出现在target中的数值忽略。
    // 最终问题转化为求arr中的最长上升子序列。
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        unordered_map<int, int> pos;
        for(int i = 0; i < n; ++i) {
            pos[target[i]] = i;
        }

        vector<int> d;
        for(int val : arr) {
            if(pos.count(val)) {
                int idx =  pos[val];
                auto iter = lower_bound(d.begin(), d.end(), idx);
                if(iter != d.end()) {
                    *iter = idx;
                } else {
                    d.push_back(idx); 
                }

                // copy(d.begin(), d.end(), ostream_iterator<int>(cout, " "));
                // cout << endl;
            }
        }

        return n - d.size();
    }
};