class Solution {
public:
    bool isPalindrome(string s) {
        string filtered = "";
        
        // keep only alphanumeric chars and make lowercase
        for (char c : s) {
            if (isalnum(c)) {
                filtered += tolower(c);
            }
        }
        
        // check if filtered string is palindrome
        string reversed = filtered;
        reverse(reversed.begin(), reversed.end());
        return filtered == reversed;
    }
};
