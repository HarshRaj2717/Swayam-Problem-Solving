bool solve(vector<int> adj[], int index, vector<bool> &vis, vector<bool> &recSt)
{
    vis[index] = true;
    recSt[index] = true;

    for (auto i : adj[index])
    {
        if (vis[i] == false && solve(adj, i, vis, recSt))
            return true;
        else if (recSt[i] == true)
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
        if (!vis[i] && solve(adj, i, vis, recSt))
            return true;
    }
    return false;
}