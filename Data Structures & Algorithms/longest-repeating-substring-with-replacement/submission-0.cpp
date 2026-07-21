class Solution {
public:
    int findMostFrequent(unordered_map<char, int> mp){
        int maxFreq = 0;
        for (const auto& pair : mp) {
            int count = pair.second;
            maxFreq = max(maxFreq, count);
        }
        return maxFreq;
    }
    int characterReplacement(string s, int k) {
        int maxFreq = 0;
        int maxLen = 0;
        int currlen = 0;
        unordered_map<char, int> mp;
        int i = 0;
        int j = 0;

        while(j < s.length()){
            char c = s[j];
            mp[c]++;
            maxFreq = findMostFrequent(mp);
            currlen = j - i + 1;
            if(currlen - maxFreq > k){
               mp[s[i]]--;
               i++;
            }else{
                maxLen = max(maxLen, currlen);
            }
            j++;
            
        }
    
        return maxLen;
        
        
    }
};
