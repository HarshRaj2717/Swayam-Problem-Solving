vector<int> dijkstra(int n, vector<pair<int, int>> adj[], int k)
{
    vector<int> dis(n, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[k] = 0;
    pq.push({0, k});
    while (!pq.empty())
    {
        int node = pq.top().second;
        int distance = pq.top().first;
        pq.pop();
        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgeWeight = it.second;
            if (distance + edgeWeight < dis[adjNode])
            {
                dis[adjNode] = distance + edgeWeight;
                pq.push({dis[adjNode], adjNode});
            }
        }
    }
    return dis;
}

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < times.size(); i++)
    {
        int u = times[i][0] - 1;
        int v = times[i][1] - 1;
        adj[u].push_back({v, times[i][2]});
    }
    vector<int> distance = dijkstra(n, adj, k - 1);
    int maxi = INT_MIN;
    for (int i = 0; i < distance.size(); i++)
    {
        if (distance[i] == 1e9)
            return -1;
        maxi = max(maxi, distance[i]);
    }
    return maxi;
}