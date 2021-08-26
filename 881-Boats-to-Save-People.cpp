class Solution {
public:
    int numRescueBoats(vector<int> &people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());

        int left = 0;
        int right = n - 1;
        int count = 0;
        while (left < right) {
            if (people[left] + people[right] <= limit) {
                left++;
                right--;
                count++;
            } else {
                count++;
                right--;
            }
        }
        if (left == right) {
            count++;
        }

        return count;
    }
};