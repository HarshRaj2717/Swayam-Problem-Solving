int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<vector<int>> mat(n, vector<int>(n, 1e9));
    for (int i = 0; i < n; i++)
    {
        mat[i][i] = 0;
    }
    for (int i = 0; i < edges.size(); i++)
    {
        int src = edges[i][0];
        int dst = edges[i][1];
        int wt = edges[i][2];
        mat[src][dst] = wt;
        mat[dst][src] = wt;
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }
    int city = 0, max_City = n;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j && mat[i][j] <= distanceThreshold)
                count++;
        }
        if (count <= max_City)
        {
            city = i;
            max_City = count;
        }
    }
    return city;
}