class Solution {
public:
    int scheduleCourse(vector<vector<int>> &courses) {
        // 贪心算法
        sort(courses.begin(), courses.end(),
             [](const auto &v1, const auto &v2) { return v1[1] < v2[1]; });

        priority_queue<int> pq;

        int totalTime = 0;
        for (auto &course : courses) {
            int duration = course[0];
            int lastDay = course[1];
            if (duration + totalTime <= lastDay) {
                totalTime += duration;
                pq.push(duration);
            } else {
                if (!pq.empty() && pq.top() > duration) {
                    totalTime -= (pq.top() - duration);
                    pq.pop();
                    pq.push(duration);
                }
            }
        }
        return pq.size();
    }
};