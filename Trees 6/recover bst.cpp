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
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;

    void solver(TreeNode* root)
    {
        if (!root)
            return;
        solver(root->left);

        if (prev && prev->val > root->val)
        {
            if (!first)
                first = prev, second = root;
            else
                second = root;
        }
        prev = root;

        solver(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first = NULL;
        second = NULL;
        prev = NULL;
        solver(root);
        swap(first->val, second->val);
    }
};