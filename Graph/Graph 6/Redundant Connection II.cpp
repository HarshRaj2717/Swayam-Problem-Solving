class DisjointSet
{
public:
    vector<int> parent, size, rank;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findParent(int u)
    {
        if (u == parent[u])
        {
            return u;
        }
        return parent[u] = findParent(parent[u]);
    }

    void UnionbyRank(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv)
            return;
        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    void UnionbySize(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv)
        {
            return;
        }
        if (size[pu] < size[pv])
        {
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        else
        {
            size[pu] += size[pv];
            parent[pv] = pu;
        }
    }
};

vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
{
    int n = edges.size();
    vector<int> inDegree(n + 1, -1);
    int num = 0, x = 0, y = -1;
    for (int i = 0; i < n; i++)
    {
        if (inDegree[edges[i][1]] != -1)
        {
            x = inDegree[edges[i][1]];
            y = i;
            break;
        }
        inDegree[edges[i][1]] = i;
    }
    DisjointSet ds(n + 1);
    for (int i = 0; i < n; i++)
    {
        if (i == y)
            continue;

        int par1 = ds.findParent(edges[i][0]);
        int par2 = ds.findParent(edges[i][1]);
        if (par1 == par2)
        {
            if (y == -1)
                return edges[i];
            return edges[x];
        }
        ds.UnionbyRank(par1, par2);
    }
    return edges[y];
}