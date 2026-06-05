class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current) {

        // When permutation size matches nums size → we're done
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        // Try choosing every unused number
        for (int i = 0; i < nums.size(); i++) {

            if (used[i]) continue;    // can't reuse number

            // pick nums[i]
            used[i] = true;
            current.push_back(nums[i]);

            // explore deeper
            backtrack(nums, used, current);

            // un-pick
            used[i] = false;
            current.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<int> current;
        backtrack(nums, used, current);
        return result;
    }
};
