class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int longest = 0;
        unordered_set<int> numSet(nums.begin(), nums.end());
        for(int num : nums) {
            if(!numSet.count(num - 1 )) {
                int currentNum = num;
                int streak = 1;
                while(numSet.count(currentNum + 1)) {
                    currentNum++;
                    streak++;

                }
                longest = max(longest, streak);
            }
        }

        return longest;
        
    }

};
