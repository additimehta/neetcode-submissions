class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            // skip non-alphanumeric from left
            if (!isalnum(s[left])) {
                left++;
                continue;
            }

            // skip non-alphanumeric from right
            if (!isalnum(s[right])) {
                right--;
                continue;
            }

            // compare after skipping
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
