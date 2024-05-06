vector<int> dijestra(int n, vector<pair<int, int>> adj[], int src)
{
    vector<int> dis(n, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
        int node = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgeWeight = it.second;
            if (dist + edgeWeight < dis[adjNode])
            {
                dis[adjNode] = dist + edgeWeight;
                pq.push({dis[adjNode], adjNode});
            }
        }
    }
    return dis;
}

vector<bool> findAnswer(int n, vector<vector<int>> &edges)
{
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
    vector<int> start = dijestra(n, adj, 0);
    vector<int> back = dijestra(n, adj, n - 1);
    int mini = start[n - 1];
    int size = edges.size();
    vector<bool> ans(size, false);
    for (int i = 0; i < size; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        if ((start[u] + wt + back[v] == mini) || (start[v] + wt + back[u] == mini))
            ans[i] = true;
    }
    return ans;
}