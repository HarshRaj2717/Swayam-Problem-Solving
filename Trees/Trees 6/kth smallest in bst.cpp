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
    int kthSmallest(TreeNode* root, int &k) {
        if (!root)
            return -1;

        int t = kthSmallest(root->left, k);
        if (t != -1)
            return t;

        if (k == 1)
            return root->val;
        k--;

        t = kthSmallest(root->right, k);
        if (t != -1)
            return t;
        return -1;
    }
};