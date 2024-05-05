int bfs(vector<vector<pair<int, int>>> &adj, int n, int start, int end)
{
    vector<int> distance(n + 1, INT_MAX);
    deque<int> dq;
    dq.push_back({start});
    distance[start] = 0;
    while (!dq.empty())
    {
        int node = dq.front();
        dq.pop_front();
        for (auto it : adj[node])
        {
            int v = it.first;
            int wt = it.second;
            if (distance[node] + wt < distance[v])
            {
                distance[v] = distance[node] + wt;
                if (wt == 1)
                {
                    dq.push_back(v);
                }
                else
                {
                    dq.push_front(v);
                }
            }
        }
    }
    return distance[end] == INT_MAX ? -1 : distance[end];
}
int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst)
{
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto it : edges)
    {
        adj[it[0]].push_back({it[1], 0});
        adj[it[1]].push_back({it[0], 1});
    }
    return bfs(adj, n, src, dst);
}