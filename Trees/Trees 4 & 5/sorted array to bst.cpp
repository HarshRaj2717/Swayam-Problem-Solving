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
    TreeNode* sortedArrayToBST(vector<int>& nums, int s = 0, int e = INT_MIN) {
        if (e == INT_MIN)
        {
            e = nums.size() - 1;
        }
        if (s > e)
        {
            return NULL;
        }
        int m = s + (e - s) / 2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = sortedArrayToBST(nums, s, m - 1);
        root->right = sortedArrayToBST(nums, m + 1, e);
        return root;
    }
};