class Solution {
    vector<int> vis;
    bool solve(int &V, vector<int> adj[], int cur) {
        if (vis[cur] == 1)
            return true;

        vis[cur] = 1;
        for (int i: adj[cur])
        {
            if (vis[cur] != 2 && solve(V, adj, i))
                return true;
        }

        vis[cur] = 2;
        return false;
    }

  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vis = vector<int> (V, 0);
        for (int i = 0; i < V; i++)
        {
            if (vis[i] != 2 && solve(V, adj, i)) {
                return true;
            }
        }
        return false;
    }
};