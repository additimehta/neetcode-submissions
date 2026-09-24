class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        // idea is to conver the piles to an array where in respect to some k
        // the number of hours taken to finish the piel
        // if the sum for that k val is  <= h
        // it can be a possible solution
        // however since we are finding the min k we should go from k -> max(val in array) 
        // as if we have that we 

        // if we keep constructing this array it will be expesnive?

        // maybe do a binary search to find the perfect val for k
        // like if the hours <= h then we can minimize and try finding on the left of k = [0,1,2,3,4..h]


        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int answer = 0;

        while(left <= right){
            int mid = (right - left)/2 + left;
            long long hours = 0;

            for(int p: piles){
                hours+= ceil((double)p / mid);
            }


            if(hours <= h){
                answer = mid;
                right = mid - 1;
            }else{
                left = mid +1;
            }
        }

        return answer;
        
    }
};
