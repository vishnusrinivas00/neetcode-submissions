#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            // Skip non-alphanumeric
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;

            // Compare lowercase characters
            if (tolower(s[left]) != tolower(s[right])) return false;

            left++;
            right--;
        }

        return true; // Only return true after checking all pairs
    }
};
