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
class Solution
{
    void solver(vector<string> &ans, TreeNode *root, string cur = "")
    {
        if (!root)
        {
            return;
        }
        if (cur.size() != 0)
            cur += "->";
        cur += to_string(root->val);
        if (!root->left && !root->right)
        {
            ans.push_back(cur);
            return;
        }
        solver(ans, root->left, cur);
        solver(ans, root->right, cur);
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (!root)
        {
            return {};
        }
        vector<string> ans;
        solver(ans, root);
        return ans;
    }
};