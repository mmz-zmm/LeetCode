class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        if (qMin.empty() || num <= qMin.top()) {
            qMin.push(num);
            if (qMax.size() + 1 < qMin.size()) {
                qMax.push(qMin.top());
                qMin.pop();
            }
        } else {
            qMax.push(num);
            if (qMax.size() > qMin.size()) {
                qMin.push(qMax.top());
                qMax.pop();
            }
        }
    }

    double findMedian() {
        if (qMin.size() > qMax.size()) {
            return qMin.top();
        }

        return (qMin.top() + qMax.top()) / 2.0;
    }
    // store value which less or equal than mean
    priority_queue<int, vector<int>, less<int>> qMin;
    // store value which greater than mean
    priority_queue<int, vector<int>, greater<int>> qMax;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */