class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;

        //contain all the frequencies 
        for(int i = 0; i < s1.length(); i++){
            mp[s1[i]]++;
        }

        unordered_map<char, int> window;
        int left = 0;
        for(int right = 0; right < s2.length(); right++){
            //expand window
            window[s2[right]]++;

            //window size is larger than s1 shrink it
            while(right - left + 1 > s1.size()){
                //shrink window
                window[s2[left]]--;

                //cleanup map cuz it can store 0 as well and map comparison would return false
                
                if(window[s2[left]] == 0){
                    window.erase(s2[left]);
                }
                left++;



            }

            // just check if both maps are equivalent


            if(window == mp){
                return true;
            }
        }

        return false;


        
    }
};