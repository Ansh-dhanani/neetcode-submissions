class Solution {
public:
    void helper(set<vector<int>>& ans,vector<int>& nums,vector<int> curr,int i){
        if(i==nums.size()){
            sort(curr.begin(),curr.end());
            ans.insert(curr);
            return;
        }

        helper(ans,nums,curr,i+1);
        curr.push_back(nums[i]);
        helper(ans,nums,curr,i+1);
        curr.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        helper(ans,nums,vector<int>(),0);
        vector<vector<int>> a(ans.begin(),ans.end());
        return a;
    }
};
