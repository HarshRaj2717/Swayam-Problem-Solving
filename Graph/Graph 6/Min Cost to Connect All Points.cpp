int mandist(vector<int> a, vector<int> b)
{
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

int minCostConnectPoints(vector<vector<int>> &points)
{
    int n = points.size();
    int ans = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(n, 0);
    pq.push({0, 0});
    while (!pq.empty())
    {
        int edgw = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (vis[node])
            continue;
        vis[node] = 1;
        ans += edgw;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                int dist = mandist(points[node], points[i]);
                pq.push({dist, i});
            }
        }
    }
    return ans;
}