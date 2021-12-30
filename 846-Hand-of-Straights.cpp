class Solution {
public:
    bool isNStraightHand(vector<int> &hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize) {
            return false;
        }

        sort(hand.begin(), hand.end());
        unordered_map<int, int> mp;
        for (auto card : hand) {
            mp[card]++;
        }

        for (auto card : hand) {
            if (!mp[card]) {
                continue;
            }
            for (int j = 0; j < groupSize; j++) {
                int newcard = card + j;
                if (!mp[newcard]) {
                    return false;
                }
                mp[newcard]--;
            }
        }

        return true;
    }
};