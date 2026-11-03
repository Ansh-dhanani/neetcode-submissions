class Solution {
   public:
    int recursion(TreeNode* r) {
        if (!r) return 0;
        int l = recursion(r->left);
        int ri = recursion(r->right);
        return 1 + max(l, ri);
    }

    int diameterOfBinaryTree(TreeNode* r) {
        if(!r) return 0;
        int ld = diameterOfBinaryTree(r->left);
        int rd = diameterOfBinaryTree(r->right);
        int c = recursion(r->left) + recursion(r->right);
        return max(c,max(ld,rd));
    }
};
