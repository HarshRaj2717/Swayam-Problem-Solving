class Solution {
    bool check(vector<vector<int>> &adj, vector<bool> &vis, int s, int d)
    {
        if (s == d)
            return true;

        if (vis[s])
            return false;

        vis[s] = true;
        for (int i = 0; i < adj[s].size(); i++)
        {
            if (check(adj, vis, adj[s][i], d))
                return true;
        }
        // vis[s] = false;

        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return check(adj, vis, source, destination);
    }
};