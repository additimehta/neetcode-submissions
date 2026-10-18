class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // u can make a max heap
        // take the top two eleements
        // if they are both same do nothing
        // if they are different then we do abs (y-x) and insert into heap
        // when do we end the simulation when the size of the heap is 1
        // or end if the size of heap is 0
        

        priority_queue<int> pq;

        for(int i = 0; i < stones.size(); i++){
            pq.push(stones[i]);
        }

        while(pq.size() > 1){
            int x = pq.top();
            pq.pop();

            int y = pq.top();
            pq.pop();

            if(x == y){
                if(pq.empty()){
                    return 0;
                }
            }else{
                int z = abs(x-y);
                pq.push(z);
            }
        }

        // pq.size() == 1 or 0
        if(pq.size() == 1){
            return pq.top();
        }else{
            return 0;
        }
    }
};
