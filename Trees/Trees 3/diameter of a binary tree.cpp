class Solution {
    int solver(TreeNode* root, int &ans) {
        if (!root)
        {
            return 0;
        }

        int l_max = solver(root->left, ans);
        int r_max = solver(root->right, ans);
        ans = max(ans, l_max + r_max);

        return 1 + max(l_max, r_max);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        int ans = 0;
        ans = max(ans, solver(root->left, ans) + solver(root->right, ans));
        return ans;
    }
};