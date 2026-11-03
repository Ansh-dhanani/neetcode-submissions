class Solution {
public:
    int recursion(int &ans,TreeNode* root){
        if(!root) return 0;

        int left=recursion(ans,root->left);
        int right=recursion(ans,root->right);

        ans=max(ans,left+right);
        return 1+max(left,right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        recursion(ans,root);
        return ans;           
    }
};
