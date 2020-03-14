class Solution {
public:
    /*
    二分法的扩展，类似于“猴子吃香蕉问题”0875-Koko-Eating-Bananas“
    */
    int shipWithinDays(vector<int>& weights, int D) {
        int low = 0;
        int high = accumulate(weights.begin(), weights.end(), 0);

        if( D == 1) return high;

        while(low < high) {
            int mid = (high - low) / 2 + low;
            if(canShip(weights, mid, D)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    bool canShip(const vector<int>& weights, int capacity, int D) {
        int day = 1;
        int remain = capacity;
        for(auto weight : weights) {
            if(weight > capacity) return false;

            remain -= weight;
            if(remain < 0) {
                day++;
                remain = capacity - weight;
            }
        }

        return day <= D;
    }
};