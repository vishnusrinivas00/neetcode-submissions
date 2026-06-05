class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& candidates, int index, int target, vector<int>& current) {
        
        // If target becomes 0 → we found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // If we run out of numbers OR target goes below 0 → stop
        if (index >= candidates.size() || target < 0) {
            return;
        }

        // 1️⃣ CHOOSE candidates[index] (we can reuse the number)
        current.push_back(candidates[index]);
        backtrack(candidates, index, target - candidates[index], current);
        current.pop_back();

        // 2️⃣ SKIP candidates[index] (move to the next number)
        backtrack(candidates, index + 1, target, current);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        backtrack(candidates, 0, target, current);
        return result;
    }
};
