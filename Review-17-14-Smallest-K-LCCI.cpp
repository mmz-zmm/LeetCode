class Solution {
public:
    vector<int> smallestK(vector<int> &arr, int k) {
        vector<int> res(k);
        if (k == 0) {
            return res;
        }

        priority_queue<int> queue;
        for (int i = 0; i < k; ++i) {
            queue.push(arr[i]);
        }

        int n = arr.size();
        for (int i = k; i < n; ++i) {
            if (arr[i] < queue.top()) {
                queue.pop();
                queue.push(arr[i]);
            }
        }

        for (int i = 0; i < k; ++i) {
            res[i] = queue.top();
            queue.pop();
        }

        return res;
    }
};