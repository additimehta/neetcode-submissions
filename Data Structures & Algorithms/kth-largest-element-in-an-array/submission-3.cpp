class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // to find the kth largest element we can do something
        // like have a min heap of size k and then then insert nums and then just get the top

        // if u have array like [10,9,8,7,6,4,1]
        // and u have k = 3 the output is 8 so we only really care about 10,9,8
        // and we select the min of that
        // so maintain a heap of a fixed sizek
        // and every time we insert something check if its larger than the min we have
        

        priority_queue<int, vector<int>, greater<int>> pq;
        for(int num : nums){
            if(pq.size()  == k){
                if(num > pq.top()){
                    pq.pop();
                    pq.push(num);
                }
            }else{
                pq.push(num);
            }
        }

        return pq.top();
    }
};
