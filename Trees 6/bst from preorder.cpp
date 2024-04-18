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
    int i = 0;
public:
    TreeNode* bstFromPreorder(vector<int>& pre, int parent = INT_MAX) {
        if (i >= pre.size() || pre[i] > parent)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[i++]);
        root->left = bstFromPreorder(pre, root->val);
        root->right = bstFromPreorder(pre, parent);
        return root;
    }
};