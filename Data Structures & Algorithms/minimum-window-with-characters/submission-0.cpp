class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        int formed = 0;
        int bestLen = INT_MAX;
        int bestStart = 0;
        int required = 0;

        for(int i = 0; i < t.size(); i++){
            need[t[i]]++;
        }

        required = need.size();

        int left = 0;



        for(int right = 0; right < s.length(); right++){
            char c = s[right];

            // expand window
            window[c]++;
            if(need.count(c) && window[c] == need[c]){
                formed++;
            }

            //shrink window
            while(formed == required){
    
                if(right-left + 1 < bestLen){
                    bestLen = right-left+1;
                    bestStart = left;
                }

                window[s[left]]--;
                if(need.count(s[left]) && window[s[left]] < need[s[left]]){
                    formed--;
                }
                left++;
            }


            // window is valid here;
            
        }
        
        if(bestLen == INT_MAX){
            return "";
        }else{
            return s.substr(bestStart, bestLen);
        }

        
    }
};