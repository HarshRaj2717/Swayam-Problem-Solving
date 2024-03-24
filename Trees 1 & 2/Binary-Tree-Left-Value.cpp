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
public:
    int ans, he = -1;
    void solve(TreeNode *a, int h)
    {
        if (!a)
            return;
        if (he < h)
        {
            ans = a->val;
            he = h;
        }
        solve(a->left, h + 1);
        solve(a->right, h + 1);
    }
    int findBottomLeftValue(TreeNode *root)
    {
        solve(root, 0);
        return ans;
    }
};