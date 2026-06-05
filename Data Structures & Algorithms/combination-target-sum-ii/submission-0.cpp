class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& candidates, int index, int target, vector<int>& current) {

        if (target == 0) {
            result.push_back(current);
            return;
        }

        if (target < 0) return;

        for (int i = index; i < candidates.size(); i++) {

            // Skip duplicates at the SAME level
            if (i > index && candidates[i] == candidates[i - 1]) 
                continue;

            current.push_back(candidates[i]);
            backtrack(candidates, i + 1, target - candidates[i], current);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> current;
        backtrack(candidates, 0, target, current);
        return result;
    }
};
