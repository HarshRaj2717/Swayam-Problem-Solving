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
    map<int, vector<pair<int, int>>> ans;
    void solve(TreeNode *r, int y, int x)
    {
        if (!r)
            return;
        ans[y].push_back({x, r->val});
        solve(r->left, y - 1, x + 1);
        solve(r->right, y + 1, x + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<pair<int, int>>> an;
        solve(root, 0, 0);
        for (auto it : ans)
            an.push_back(it.second);
        for (auto &it : an)
            sort(it.begin(), it.end());
        vector<vector<int>> q;
        for (auto it : an)
        {
            vector<int> t;
            for (auto itt : it)
                t.push_back(itt.second);
            q.push_back(t);
        }
        return q;
    }
};