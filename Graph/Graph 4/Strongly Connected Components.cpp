void dfspush(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfspush(it, vis, adj, st);
        }
    }
    st.push(node);
}

void dfs(int node, vector<int> &vis, vector<vector<int>> &adjRev)
{
    vis[node] = 1;
    for (auto it : adjRev[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adjRev);
        }
    }
}

int kosaraju(int V, vector<vector<int>> &adj)
{
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfspush(i, vis, adj, st);
        }
    }
    vector<vector<int>> adjRev(V);
    for (int i = 0; i < V; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            adjRev[it].push_back(i);
        }
    }

    int cnt = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            cnt++;
            dfs(node, vis, adjRev);
        }
    }
    return cnt;
}