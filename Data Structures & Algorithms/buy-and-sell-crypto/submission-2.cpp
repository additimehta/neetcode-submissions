class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // the goal is to find a max value on the RHS
        // and find a min value on LHS
        int minVal = prices[0];
        int maxProfit = 0;

        for(int i = 0; i < prices.size(); i++){

            

            // minVal = 1 - 10 -> - 
            // maxPorfit = nums[i] - minVal >
            maxProfit = max(maxProfit, prices[i] - minVal); 
            minVal = min(minVal, prices[i]);

        }
        return maxProfit;

        

        
    }
};
