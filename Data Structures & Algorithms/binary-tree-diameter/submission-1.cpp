class Solution {
   public:
    int recursion(TreeNode* root) {
        if (!root) return 0;

        int left = recursion(root->left);
        int right = recursion(root->right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
        int current = recursion(root->left) + recursion(root->right);
        return max(current,max(leftDiameter,rightDiameter));
    }
};
