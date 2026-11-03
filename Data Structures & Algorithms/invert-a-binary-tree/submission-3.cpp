class Solution {
public:
    void recursion(TreeNode* &root){
        if(!root) return;
        if(!root->left && !root->right) return;
        
        if(!root->right && root->left){
            root->right=root->left;
            root->left=nullptr;
        }
        else if(!root->left && root->right){
            root->left=root->right;
            root->right=nullptr;
        }
        else if(root->left && root->right){
            TreeNode* temp=root->left;
            root->left=root->right;
            root->right=temp;
        }
        
        recursion(root->left);
        recursion(root->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        TreeNode *head=root;
        recursion(head);
        return root;
    }
};
