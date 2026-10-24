class Solution {
public:

    string encode(vector<string>& strs) {

        // for each str in strs we store [lenght]#str

        string ans = "";
        if(strs.empty()){
            return ans;
        }

        for(string s : strs){
            ans+=to_string(s.size());
            ans+="#";
            ans+=s;
        }
        return ans;
    

    }

    vector<string> decode(string s) {
        vector<string> sol;
        int i = 0; 
        while(i < s.size()){
            string length = "";
            while(s[i] != '#'){
                length+=s[i];
                i++;
            }

            int len = stoi(length);
            i++;
            string str = "";


            while(len > 0){
                str += s[i];
                i++;
                len--;
            }

            sol.push_back(str);

        }

        return sol;

    }
};
