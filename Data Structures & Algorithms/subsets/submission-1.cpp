class Solution {
public:
    void helper(vector<vector<int>>&ans,vector<int>&nums,int i,vector<int> curr){
        if(i==nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        helper(ans,nums,i+1,curr);
        curr.pop_back();
        helper(ans,nums,i+1,curr);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(ans,nums,0,vector<int>());
        return ans;
    }
};
