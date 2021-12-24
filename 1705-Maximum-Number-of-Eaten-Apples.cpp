class Solution {
public:
    int eatenApples(vector<int> &apples, vector<int> &days) {
        int res = 0;
        int i = 0;
        int n = days.size();

        map<int, int> apples_map;
        while (i < n || !apples_map.empty()) {
            if (i < n) {
                apples_map[days[i] + i - 1] += apples[i];
            }

            // 尝试从map中取出一个最接近过期但是没有过期的苹果
            while (!apples_map.empty()) {
                auto it = apples_map.begin();
                // 苹果过期或吃完了
                if (it->first < i || it->second == 0) {
                    apples_map.erase(it->first);
                } else {
                    // 吃一个
                    res++;
                    it->second--;
                    break;
                }
            }
            i++;
        }

        return res;
    }
};

class Solution {
public:
    int eatenApples(vector<int> &apples, vector<int> &days) {
        int res = 0;
        int d = 0;
        int n = days.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        while (d < n) {
            if (apples[d] > 0) {
                pq.emplace(days[d] + d - 1, apples[d]);
            }

            while (!pq.empty() && pq.top().first < d) {
                pq.pop();
            }

            if (!pq.empty()) {
                auto apple = pq.top();
                pq.pop();
                apple.second--;
                if (apple.second != 0) {
                    pq.push(apple);
                }
                res++;
            }
            d++;
        }

        while (!pq.empty()) {
            while (!pq.empty() && pq.top().first < d) {
                pq.pop();
            }

            if (pq.empty()) {
                break;
            }

            auto apple = pq.top();
            pq.pop();
            int num = min(apple.first - d + 1, apple.second);
            // cout << num;
            res += num;
            d += num;
        }

        return res;
    }
};