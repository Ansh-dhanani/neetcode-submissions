class Solution {
   public:
    void helper(vector<vector<int>>& ans, vector<int>& nums, int target, vector<int> &curr, int total, int i) {
        if (total == target) {
            ans.push_back(curr);
            return;
        }
        if (i >= nums.size() || total > target) {
            return;
        } else {
            curr.push_back(nums[i]);
            helper(ans, nums, target, curr, total+nums[i], i);

            curr.pop_back();
            helper(ans, nums, target, curr, total, i + 1);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(ans, nums, target, curr, 0, 0);
        return ans;
    }
};
