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
    bool traverse(TreeNode* root, int &k, unordered_set<int> &s)
    {
        if (!root)
            return false;

        if (s.count(k - root->val) != 0)
            return true;
        s.insert(root->val);

        return traverse(root->left, k, s) || traverse(root->right, k, s);        
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return traverse(root, k, s);
    }
};