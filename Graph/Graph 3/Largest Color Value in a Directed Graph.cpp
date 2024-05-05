int largestPathValue(string colors, vector<vector<int>> &edges)
{
    int n = colors.size();
    vector<int> adj[n];
    vector<int> inDegree(n, 0);
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        inDegree[it[1]]++;
    }
    queue<int> q;
    vector<vector<int>> nodeToAllColor(n, vector<int>(26, 0));
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
            nodeToAllColor[i][colors[i] - 'a'] = 1;
        }
    }
    int answer = 0;
    int countNodes = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        countNodes++;
        for (int &AdjNode : adj[node])
        {
            for (int Color = 0; Color < 26; Color++)
            {
                nodeToAllColor[AdjNode][Color] =
                    max(nodeToAllColor[AdjNode][Color],
                        nodeToAllColor[node][Color] +
                            (colors[AdjNode] - 'a' == Color ? 1 : 0));
            }
            inDegree[AdjNode]--;
            if (inDegree[AdjNode] == 0)
                q.push(AdjNode);
        }
        answer = max(answer, *max_element(nodeToAllColor[node].begin(), nodeToAllColor[node].end()));
    }
    return countNodes < n ? -1 : answer;
}