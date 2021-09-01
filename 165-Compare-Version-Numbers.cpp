class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size();
        int n2 = version2.size();
        int left1 = 0;
        int right1 = 0;
        int v1 = 0;
        int left2 = 0;
        int right2 = 0;
        int v2 = 0;

        while (right1 < n1 || right2 < n2) {
            while (right1 < n1 && version1[right1] != '.') {
                right1++;
            }
            if (right1 == left1) {
                v1 = 0;
            } else {
                v1 = stoi(version1.substr(left1, right1 - left1));
                left1 = right1 + 1;
                right1 = left1;
            }

            while (right2 < n2 && version2[right2] != '.') {
                right2++;
            }
            if (right2 == left2) {
                v2 = 0;
            } else {
                v2 = stoi(version2.substr(left2, right2 - left2));
                left2 = right2 + 1;
                right2 = left2;
            }

            // cout << v1 << " "<< v2<<endl;

            if (v1 < v2) {
                return -1;
            } else if (v1 > v2) {
                return 1;
            }
        }
        return 0;
    }
};