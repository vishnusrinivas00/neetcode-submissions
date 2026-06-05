class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());  // populate set

        int longest = 0;
        for (int num : numSet) {
            // only start counting at the beginning of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int streak = 1;

                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    streak++;
                }

                longest = max(longest, streak);
            }
        }

        return longest;
    }
};
