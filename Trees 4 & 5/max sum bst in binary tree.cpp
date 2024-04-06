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
    struct quad {
        bool isBST;
        int mini;
        int maxi;
        int cur;
    };

    quad solver(TreeNode* root, int& ans)
    {
        quad temp;
        if (!root)
        {
            temp.isBST = true;
            temp.mini = INT_MAX;
            temp.maxi = INT_MIN;
            temp.cur = 0;
            return temp;
        }

        quad l = solver(root->left, ans);
        quad r = solver(root->right, ans);

        if (l.isBST && r.isBST && root->val > l.maxi && root->val < r.mini)
        {
            temp.isBST = true;
            temp.mini = min(l.mini, root->val);
            temp.maxi = max(r.maxi, root->val);
            temp.cur = root->val + l.cur + r.cur;
            ans = max(ans, temp.cur);
            return temp;
        }

        temp.isBST = false;
        return temp;
    }

public:
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        solver(root, ans);
        return ans;
    }
};