class Solution {
public:
    bool isAnagram(string s, string t) {


        if(s.size() != t.size()){
            return false;
        }

        unordered_map<char, int> mp;

        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
        }

        for(int j = 0; j < t.size(); j++){
            if(mp.contains(t[j])){
                mp[t[j]]--;
            }else{
                return false;
            }
        }


        for(auto [key, val] : mp){
            if(val < 0 || val > 0){
                return false;
            }
        }

        return true;
        
    }
};
