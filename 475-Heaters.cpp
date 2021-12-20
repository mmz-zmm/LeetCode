class Solution {
public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        int ans = 0;

        sort(heaters.begin(), heaters.end());

        for (auto house : houses) {
            auto iter_j = upper_bound(heaters.begin(), heaters.end(), house);
            auto iter_i = iter_j - 1;
            int rightDis =
                (iter_j >= heaters.end()) ? INT_MAX : (*iter_j - house);
            int leftDis =
                (iter_i < heaters.begin()) ? INT_MAX : (house - *iter_i);
            int currentDis = min(leftDis, rightDis);
            ans = max(ans, currentDis);
        }

        return ans;
    }
};