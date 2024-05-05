void dfs(int node, vector<int> adj[], vector<int> &ds, vector<bool> &vis)
{
    vis[node] = true;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            ds.push_back(it);
            dfs(it, adj, ds, vis);
        }
    }
}
vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
{
    vector<int> adj[n];
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        vector<int> ds;
        vector<bool> vis(n, false);
        dfs(i, adj, ds, vis);
        sort(ds.begin(), ds.end());
        ans.push_back(ds);
    }
    return ans;
}