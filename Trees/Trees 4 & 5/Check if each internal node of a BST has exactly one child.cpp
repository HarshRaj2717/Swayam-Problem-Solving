#include <bits/stdc++.h>

using namespace std;

bool hasOnlyOneChild(vector<int> &pre)
{
    if (pre.size() == 0)
        return true;
    for (int i = 0; i < pre.size() - 1; i++)
    {
        if (!(pre[i] < pre[i + 1] && pre[i] < pre[pre.size() - 1] || pre[i] > pre[i + 1] && pre[i] > pre[pre.size() - 1]))
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<int> pre(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }

    hasOnlyOneChild(pre) ? cout << "TRUE" : cout << "FALSE";
    cout << endl;

    return 0;
}