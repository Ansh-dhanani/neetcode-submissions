class Solution {
public:
    void helper(vector<int>& curr,vector<vector<int>>& ans,int i){
        if(i==curr.size()-1){
            ans.push_back(curr);
            return;
        }
        for(int j=i;j<curr.size();j++){
            swap(curr[i],curr[j]);
            helper(curr,ans,i+1);
            swap(curr[i],curr[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums,ans,0);
        return ans;
    }
};
