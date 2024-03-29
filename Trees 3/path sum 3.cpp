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
    void count(TreeNode* root, int& targetSum, int& t, long long cur = 0) {
        if (!root)
        {
            return;
        }
        cur += root->val;
        if (cur == targetSum)
        {
            t++;
        }
        count(root->left, targetSum, t, cur);
        count(root->right, targetSum, t, cur);
    }
    void solver(TreeNode* root, int& targetSum, int& ans) {
        if (!root)
            return;
        int t = 0;
        count(root, targetSum, t);
        ans += t;
        solver(root->left, targetSum, ans);
        solver(root->right, targetSum, ans);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        solver(root, targetSum, ans);
        return ans;
    }
};