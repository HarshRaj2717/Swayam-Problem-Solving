
class Solution
{
public:
    map<int, pair<int, int>> mp;
    void solve(Node *r, int y, int x)
    {
        if (!r)
            return;
        if (mp.find(y) == mp.end() || (mp.find(y) != mp.end() && mp[y].first < x))
            mp[y] = {x, r->data};
        solve(r->right, y + 1, x + 1);
        solve(r->left, y - 1, x + 1);
    }
    vector<int> bottomView(Node *root)
    {
        // Your Code Here
        solve(root, 0, 0);
        vector<int> ans;
        for (auto it : mp)
            ans.push_back(it.second.second);
        return ans;
    }
};