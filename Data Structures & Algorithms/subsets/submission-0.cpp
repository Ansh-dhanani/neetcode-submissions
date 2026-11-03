class Solution {
public:
    void generate(vector<vector<int>> &ans,vector<int>& nums,int i,vector<int> curr){
        if(i==nums.size()) {
            ans.push_back(curr);
            return;
        };
        curr.push_back(nums[i]);
        generate(ans,nums,i+1,curr);
        curr.pop_back();
        generate(ans,nums,i+1,curr);
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        generate(ans,nums,0,vector<int>());
        return ans;
    }
};
