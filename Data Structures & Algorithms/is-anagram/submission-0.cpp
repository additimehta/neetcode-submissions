class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s1;
        unordered_map<char, int> s2;

        for(char c : s) {
            s1[c]++;
        }

        for(char c : t) {
            s2[c]++;
        }

        return s1 == s2;


        
    }
};
