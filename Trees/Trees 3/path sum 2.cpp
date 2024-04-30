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
    void solver(TreeNode* root, vector<vector<int>>& ans, int targetSum, vector<int> cur2 = {}, int cur = 0) {
        if (!root)
        {
            return;
        }
        cur += root->val;
        cur2.push_back(root->val);
        if (!root->left && !root->right)
        {
            if (cur == targetSum)
            {
                ans.push_back(cur2);
            }
            return;
        }
        solver(root->left, ans, targetSum, cur2, cur);
        solver(root->right, ans, targetSum, cur2, cur);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        solver(root, ans, targetSum);
        return ans;
    }
};