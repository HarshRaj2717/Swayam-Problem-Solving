bool dfs(vector<int> adj[], int index, vector<bool> &vis, vector<bool> &recSt)
{
    vis[index] = true;
    recSt[index] = true;

    for (auto node : adj[index])
    {
        if (vis[node] == false && dfs(adj, node, vis, recSt))
            return true;
        else if (recSt[node] == true)
            return true;
    }
    recSt[index] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> vis(V, false);
    vector<bool> recSt(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i] && dfs(adj, i, vis, recSt))
            return true;
    }
    return false;
}