class Solution {
    // vector<int> vis;
    // vector<vector<int>> adj;
    // vector<int> parents;
    // void dfs(int cur) {
    //     if (vis[cur])
    //         return;

    //     vis[cur] = true;
    //     for (int i: adj[cur])
    //     {
    //         parents[i] = false;
    //         dfs(i);
    //     }
    // }
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // vis = vector<int> (n, false);
        // parents = vector<int> (n, false);
        // adj = vector<vector<int>> (n);
        // for (int i = 0; i < edges.size(); i++)
        // {
        //     adj[edges[i][0]].push_back(edges[i][1]);
        // }

        // for (int i = 0; i < n; i++)
        // {
        //     if (!vis[i])
        //     {
        //         parents[i] = true;
        //         dfs(i);
        //     }
        // }

        vector<bool> noIndegree(n, true);

        for (int i = 0; i < edges.size(); i++) {
            noIndegree[edges[i][1]] = false;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (noIndegree[i])
                ans.push_back(i);
        return ans;
    }
};