class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
         int left = 1;
         int right = *(max_element(piles.begin(), piles.end()));

         while(left < right) {
             int mid = (right - left) / 2 + left;
             if(canEatAllBanana(piles, H, mid)) {
                 right = mid;
             } else {
                 left = mid + 1;
             }
         }

         return left;
    }

    bool canEatAllBanana(const vector<int>& piles, int H, int K) {
        int act_H = 0;
        for(auto pile : piles) {
            act_H += (pile - 1)/K + 1;
        }
        return act_H <= H;
    }
};
