class MedianFinder {
private:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if(min_heap.size() == 0 && max_heap.size() == 0){
            min_heap.push(num);
            return;
        }
        
        if(min_heap.size() == max_heap.size()){
            if(num < max_heap.top()){
               int temp = max_heap.top();
               max_heap.pop();
               max_heap.push(num);
               min_heap.push(temp); 
            }else{
              min_heap.push(num);  
            }
        }else if(min_heap.size() > max_heap.size()){
            if(num > min_heap.top()){
                int temp = min_heap.top();
                min_heap.pop();
                max_heap.push(temp);
                min_heap.push(num);
            }else{
                max_heap.push(num);
            }
        }else{  
            if(num < max_heap.top()){
               int temp = max_heap.top();
               max_heap.pop();
               max_heap.push(num);
               min_heap.push(temp);
            }else{
                min_heap.push(num);
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(min_heap.size() == 0 && max_heap.size() == 0){
            return 0;
        }
        
        if(min_heap.size() == max_heap.size()){
            return (min_heap.top() + max_heap.top()) / 2.0;
        }  
        
        return min_heap.size() > max_heap.size() ? min_heap.top() : max_heap.top();
    }
};
