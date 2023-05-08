class MedianFinder {
private:
    priority_queue<int>maxHeap ;
    priority_queue<int, vector<int>, greater<>>minHeap ;

public:
    MedianFinder() { } 
      void addNum(int num) {
            if(maxHeap.empty() || num <= maxHeap.top()){
                    maxHeap.push(num) ;
        }
        else
            minHeap.push(num) ;

        if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top()) ;
            minHeap.pop() ;
        }

        else if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top()) ;
            maxHeap.pop() ;
        }
    }

    double findMedian() {
        if(maxHeap.size() > minHeap.size())
            return maxHeap.top() ;
        else
            return ((double)maxHeap.top() + minHeap.top()) / 2 ;
    } 
}
