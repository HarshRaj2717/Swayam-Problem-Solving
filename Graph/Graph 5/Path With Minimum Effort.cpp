int minimumEffortPath(vector<vector<int>> &heights)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int rows = heights.size();
    int columns = heights[0].size();
    vector<vector<int>> dis(rows, vector<int>(columns, 1e9));
    dis[0][0] = 0;
    pq.push({0, {0, 0}});
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int diff = it.first;
        int row = it.second.first;
        int col = it.second.second;
        if (row == rows - 1 && col == columns - 1)
            return diff;
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if (nrow >= 0 && nrow < rows && ncol >= 0 && ncol < columns)
            {
                int newEffort = max(abs(heights[row][col] - heights[nrow][ncol]), diff);
                if (newEffort < dis[nrow][ncol])
                {
                    dis[nrow][ncol] = newEffort;
                    pq.push({newEffort, {nrow, ncol}});
                }
            }
        }
    }
    return dis[rows - 1][columns - 1];
}