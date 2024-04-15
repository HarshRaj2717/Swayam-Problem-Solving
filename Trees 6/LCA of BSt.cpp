/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val)
            return lowestCommonAncestor(root, q, p);
        if (!root)
            return NULL;


        if (p->val <= root->val && root->val <= q->val)
                return root;
        TreeNode* a = lowestCommonAncestor(root->left, p, q);
        if (a)
            return a;
        return lowestCommonAncestor(root->right, p, q);
    }
};