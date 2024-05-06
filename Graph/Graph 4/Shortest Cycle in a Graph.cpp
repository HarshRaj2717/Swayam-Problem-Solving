void bfs(int src, vector<int> adj[], int n, int &ans)
{
    vector<int> dist(n, 1e9);
    vector<int> parent(n, -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (dist[it] == (int)(1e9))
            {
                dist[it] = 1 + dist[node];
                parent[it] = node;
                q.push(it);
            }
            else if (parent[node] != it)
            {
                ans = min(ans, dist[it] + dist[node] + 1);
            }
        }
    }
}

int findShortestCycle(int n, vector<vector<int>> &edges)
{
    vector<int> adj[n + 1];
    int ans = INT_MAX;
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    for (int i = 0; i < n; i++)
    {
        bfs(i, adj, n, ans);
    }
    if (ans == INT_MAX)
        return -1;
    return ans;
}