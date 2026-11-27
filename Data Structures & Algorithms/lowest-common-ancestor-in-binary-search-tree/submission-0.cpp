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
    bool helper(TreeNode* root,TreeNode* p, TreeNode* q, TreeNode*& ans){
        if(!root) return false;

        bool left=helper(root->left,p,q,ans);
        bool right=helper(root->right,p,q,ans);

        if((left && right)||((root==p || root==q)&&(left||right))){
            ans=root;
            return true;
        }

        return  left || right || (root == p || root == q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=root;
        helper(root,p,q,ans);
        return ans;
    }
};
