nt findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
{
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < flights.size(); i++)
    {
        adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
    }
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, src}});
    vector<int> dis(n, 1e9);
    dis[src] = 0;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int cost = it.second.first;
        int node = it.second.second;
        if (stops > K)
            continue;
        for (auto i : adj[node])
        {
            int adjNode = i.first;
            int edgeWeight = i.second;
            if (cost + edgeWeight < dis[adjNode] && stops <= K)
            {
                dis[adjNode] = cost + edgeWeight;
                q.push({stops + 1, {dis[adjNode], adjNode}});
            }
        }
    }
    if (dis[dst] == 1e9)
        return -1;
    return dis[dst];
}