class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {

        // to get the kth largest we have to convert this nums into a heap tree
        // the top of the heap tree is the first largest
        // so if we remove the top k - 1 times
        // and then get the top we will get the kth largest

        // however we are erasing some data with pop
        // is there a way we can just directly access the kth largest
        // if the heap has 10 elements the 10th largest is top of a min heap
        // it is the actually the smallest element
        // why not just always maintain the heap of size k 
        // the k val never changes so anything out of the scope of the k values are not relevant


        this->k = k;
        for(int num : nums){
            pq.push(num);
            if(pq.size() > k){
                pq.pop();
            }
        } 

    
    }
    
    int add(int val) {
        pq.push(val);

        // if we use a min heap 
        // if we add the element and it increase the size of the heap
        if(pq.size() > k){
            pq.pop();
        }

        return pq.top();

    }
};
