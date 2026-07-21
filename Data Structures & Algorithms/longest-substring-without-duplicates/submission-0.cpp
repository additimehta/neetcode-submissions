class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int res = 0;
        unordered_map<char, int> freq;


        for(int r = 0; r < s.length(); r++) {
            freq[s[r]]++;

            while(freq[s[r]] >= 2) {
                freq[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};