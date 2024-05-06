vector<double> blackbox(vector<pair<int, double>> adj[], int src, int n)
{
    vector<double> dis(n, 0);
    priority_queue<pair<double, int>> pq;
    pq.push({1.0, src});
    while (!pq.empty())
    {
        double weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto it : adj[node])
        {
            int edgeValue = it.first;
            double edgeWeight = it.second;
            if (weight * edgeWeight > dis[edgeValue])
            {
                dis[edgeValue] = weight * edgeWeight;
                pq.push({dis[edgeValue], edgeValue});
            }
        }
    }
    return dis;
}
double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
{
    vector<pair<int, double>> adj[n];
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
        adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
    }
    vector<double> ans = blackbox(adj, start_node, n);
    return ans[end_node];
}