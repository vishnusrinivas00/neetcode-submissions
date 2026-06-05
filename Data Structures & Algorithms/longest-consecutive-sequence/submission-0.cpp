#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> freq(nums.begin(), nums.end()); // put all numbers in a set
        int maxLen = 0;

        for (int num : freq) {
            // Only start counting if num is the start of a sequence
            if (!freq.count(num - 1)) {
                int current = num;
                int streak = 1;

                while (freq.count(current + 1)) {
                    current++;
                    streak++;
                }

                maxLen = max(maxLen, streak);
            }
        }

        return maxLen;
    }
};
