/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void helper(TreeNode* r,vector<vector<int>>& ans,int level){
        if(!r) return;

        if(ans.size()-1<level){
            ans.push_back(vector<int>());
        }
        ans[level].push_back(r->val);

        helper(r->left,ans,level+1);
        helper(r->right,ans,level+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        ans.push_back(vector<int>());
        helper(root,ans,0);
        return ans;
    }
};
