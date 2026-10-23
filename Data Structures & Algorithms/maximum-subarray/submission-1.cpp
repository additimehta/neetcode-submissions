class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // the greedy approach is to either take the number
        // we keep a track of a currsum and a best sum
        // the best sum is what we have to return
        // in the currsum it will either include the new number or it will start a new subarray at that new number

        int bestSum = nums[0];
        int currSum = nums[0];


        for(int i = 1; i < nums.size(); i++){
            // either we include in our currSum, or we start a new subaray from that nums
            currSum = max(nums[i], currSum + nums[i]);
            bestSum = max(currSum, bestSum);
        }

        return bestSum;
    }
};
