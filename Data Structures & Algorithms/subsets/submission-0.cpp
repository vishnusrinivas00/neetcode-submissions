class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, int index, vector<int>& current) {
        
        // Whatever is currently in "current" is a valid subset
        result.push_back(current);

        // Try choosing every element starting from "index"
        for (int i = index; i < nums.size(); i++) {
            
            // CHOOSE nums[i]
            current.push_back(nums[i]);

            // EXPLORE further choices, starting from the next index
            backtrack(nums, i + 1, current);

            // UN-CHOOSE (remove the last chosen number)
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        backtrack(nums, 0, current);
        return result;
    }
};

