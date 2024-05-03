class Solution {
    void visit(const vector<vector<int>>& isConnected, vector<bool>& vis, int cur) {
        if (cur >= isConnected.size() || vis[cur])
            return;

        vis[cur] = true;

        for (int i = 0; i < isConnected.size(); i++)
        {
            if (i == cur || isConnected[cur][i] == 0)
                continue;
            visit(isConnected, vis, i);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        vector<bool> vis(isConnected.size(), false);
        for (int i = 0; i < isConnected.size(); i++) {
            if (vis[i])
                continue;
            ans++;
            visit(isConnected, vis, i);
        }
        return ans;
    }
};