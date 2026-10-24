class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // for 2 anagrams: if we sort them they will be the same
        // so cat -> act 


        unordered_map<string, vector<string>> mp;

        for(string s : strs){
            string sorted = s;
            sort(sorted.begin(), sorted.end());

            mp[sorted].push_back(s);
        }

        vector<vector<string>> sol;


        for(auto &[key, val] : mp){
            sol.push_back(val);
        }

        return sol;
        

    }
};
