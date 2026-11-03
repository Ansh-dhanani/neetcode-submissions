class Solution {
   public:
    void helper(vector<int>& candidates, int target, vector<int> curr, int total, int i,
                vector<vector<int>>& ans) {
        if (total == target) {
            ans.push_back(curr);
            return;
        }
        if (total > target) {
            return;
        }
        for (int j = i; j < candidates.size(); j++) {
            if (j > i && candidates[j] == candidates[j - 1]) {
                continue;
            }
            curr.push_back(candidates[j]);
            helper(candidates, target, curr, total + candidates[j], j+1, ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        helper(candidates, target, vector<int>(), 0, 0, ans);
        return ans;
    }
};
