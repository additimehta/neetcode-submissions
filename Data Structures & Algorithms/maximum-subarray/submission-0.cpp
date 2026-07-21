class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        // T represents the maximum sum from subarray
        //from 0 to the ith index
        vector<int> T(n);
        // base case
        T[0] = nums[0];
        int best = nums[0];

        for(int i = 1; i < n; i++){
            // two options
            // 1 take the current index 
            // dont take it because we found a better subarray
            T[i] = max(T[i - 1] + nums[i], nums[i]);
            // update the value of the highest T[i] value
            best = max(T[i], best);
        }

        return best;

    }
};
