/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 bool solver(vector<int>& ans, TreeNode* A, int& B)
 {
     if (!A)
        return false;
    if (A->val == B)
    {
        ans.push_back(A->val);
        return true;
    }
    if(solver(ans, A->left, B))
    {
        ans.push_back(A->val);
        return true;
    }
    else if (solver(ans, A->right, B)) {
        ans.push_back(A->val);
        return true;
    }
    return false;
 }
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    solver(ans, A, B);
    reverse(ans.begin(), ans.end());
    return ans;
}
