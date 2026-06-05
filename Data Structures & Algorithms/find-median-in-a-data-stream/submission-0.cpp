class MedianFinder {
public:
    priority_queue<int> low; // max heap
    priority_queue<int, vector<int>, greater<int>> high; // min heap

    void addNum(int num) {
        low.push(num);                   // put in low first
        high.push(low.top());            // largest of low → high
        low.pop();

        if (high.size() > low.size()) {  // balance sizes
            low.push(high.top());
            high.pop();
        }
    }

    double findMedian() {
        if (low.size() > high.size()) {
            return low.top();            // odd count
        }
        return (low.top() + high.top()) / 2.0; // even count
    }
};
