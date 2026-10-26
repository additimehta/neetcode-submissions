class Solution {
public:

    bool isPalindrome(string s) {

        // ignore the space
        int left = 0;
        int right = s.size() - 1;
        string str = "";

        while(left <= right){
            if(!isalnum(s[left])){
                left++;
                continue;
            }

            if(!isalnum(s[right])){
                right--;
                continue;
            }

            if(tolower(s[left])== tolower(s[right])){
                left++;
                right--;
            }else{
                return false;
            }
        }

        return true;
        
    }
};
