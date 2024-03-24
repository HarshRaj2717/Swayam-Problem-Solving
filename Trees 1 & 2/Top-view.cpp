
class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    map<int, pair<int, int>> mp;
    void solve(Node *r, int y, int x)
    {
        if (!r)
            return;
        if (mp.find(y) == mp.end() || (mp.find(y) != mp.end() && mp[y].first > x))
            mp[y] = {x, r->data};
        solve(r->left, y - 1, x + 1);
        solve(r->right, y + 1, x + 1);
    }
    vector<int> topView(Node *root)
    {
        // Your code here
        solve(root, 0, 0);
        vector<int> ans;
        for (auto it : mp)
            ans.push_back(it.second.second);
        return ans;
    }
};