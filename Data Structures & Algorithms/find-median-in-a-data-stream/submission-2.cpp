class MedianFinder {

private:
    priority_queue<int, vector<int>, greater<int>> min_hp;
    priority_queue<int> max_hp;
public:
    MedianFinder() {}


    
    void addNum(int num) {
        // what happens when u add a number however
        // maybe reconstruct the whole thin

        // max heap => first half
        // min heap -> second half 
        // if element is greater than > min_heap top (because it belings in second half )then push to min heap

        // or think of it like if the new num is <= max_hp.top then it belondgs in min heap
        // else push to max heap
        // also if the size of the 2 heaps difference is > 1 then we need to rebalance
        // to relebalance is take the heap with the larger size and push into smaller heap

        if(max_hp.empty() || num <= max_hp.top()){
            max_hp.push(num);
        }else{
            min_hp.push(num);
        }

        if(max_hp.size() > min_hp.size() +1){
            min_hp.push(max_hp.top());
            max_hp.pop();
        }

        if(min_hp.size() > max_hp.size() + 1){
            max_hp.push(min_hp.top());
            min_hp.pop();
        }
        
    }
    
    double findMedian() {
        // we can keep two heaps
        // max heap for the first n/2 elements
        // the min heap is for the remaining elements which is n/2 or n/2+1
        // so for example if u have an array of 
        // [1,2,3] 
        // the max heap would just be 1 and then in min heap it is 2,3
        // and u just the min heap top which is 2
        // in the case that u have event elements its just top of min and top of max and avg    
        // even numbers
        if(min_hp.size() == max_hp.size()){
            return((min_hp.top() + max_hp.top()) / 2.0);
        }else if(max_hp.size() > min_hp.size()){
            return max_hp.top();
        }else{
            return min_hp.top();
        }

        
    }
};
