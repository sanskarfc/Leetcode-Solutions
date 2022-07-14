class MedianFinder {
public:
    MedianFinder(){
        // default constructor
    }
    
    priority_queue<int,vector<int>,greater<int>> minHeap; // right side
	priority_queue<int> maxHeap; // left side

    void addNum(int num) {
        if(maxHeap.empty() || maxHeap.top() > num){
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }
        
        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size() > maxHeap.size() + 1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()){
            if(maxHeap.empty()) return 0;
            else{
                double median = (maxHeap.top() + minHeap.top())/2.0;
                return median;
            }
        }
        else{
            if(maxHeap.size() > minHeap.size()){
                return maxHeap.top();
            }
            else{
                return minHeap.top();
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */