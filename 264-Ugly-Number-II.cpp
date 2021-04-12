class Solution {
public:
    typedef long long LL;
    int nthUglyNumber(int n) {
        if (n == 1) {
            return 1;
        }

        vector<int> dp(n, 0);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        int next_2;
        int next_3;
        int next_5;
        for (int i = 1; i < n; ++i) {
            next_2 = dp[p2] * 2;
            next_3 = dp[p3] * 3;
            next_5 = dp[p5] * 5;
            dp[i] = min(min(next_2, next_3), next_5);
            if (dp[i] == next_2) {
                p2++;
            }
            if (dp[i] == next_3) {
                p3++;
            }
            if (dp[i] == next_5) {
                p5++;
            }
        }
        return dp[n - 1];
    }

    int nthUglyNumberByMinHeap(int n) {
        if (n == 1) {
            return 1;
        }

        set<LL> s;
        priority_queue<LL, vector<LL>, greater<LL>> q;
        q.push(1);
        s.insert(1);

        int ans = 1;
        LL next = 1;
        while (n--) {
            long curr = q.top();
            q.pop();
            ans = (int)curr;
            for (auto num : {2, 3, 5}) {
                next = curr * num;
                if (s.count(next)) {
                    continue;
                }
                s.insert(next);
                q.push(next);
            }
        }
        return ans;
    }
};