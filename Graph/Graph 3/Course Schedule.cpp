bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> adj[numCourses];
    for (int i = 0; i < prerequisites.size(); i++)
    {
        adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    int indegree[numCourses];
    for (int i = 0; i < numCourses; i++)
    {
        indegree[i] = 0;
    }
    for (int i = 0; i < numCourses; i++)
    {
        for (auto it : adj[i])
            indegree[it]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    if (topo.size() == numCourses)
        return true;
    else
        return false;
}