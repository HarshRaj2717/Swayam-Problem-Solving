vector<int> dijkstra(int V, vector<vector<pair<int, int>>> adj, int S, vector<int> &disappear)
{
    vector<int> dis(V, INT_MAX);
    vector<bool> vis(V, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[S] = 0;
    pq.push({0, S});
    while (!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (vis[node] == 1)
            continue;
        vis[node] = 1;
        for (auto it : adj[node])
        {
            int edgeWeight = it.second;
            int adjNode = it.first;
            if (dist + edgeWeight < disappear[adjNode])
            {
                if (dist + edgeWeight < dis[adjNode])
                {
                    dis[adjNode] = dist + edgeWeight;
                    pq.push({dis[adjNode], adjNode});
                }
            }
        }
    }
    return dis;
}

vector<int> minimumTime(int n, vector<vector<int>> &edges, vector<int> &disappear)
{
    vector<vector<pair<int, int>>> adj(n);
    vector<int> road;
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
    road = dijkstra(n, adj, 0, disappear);
    for (int i = 0; i < n; i++)
    {
        if (road[i] == INT_MAX)
            road[i] = -1;
    }
    return road;
}