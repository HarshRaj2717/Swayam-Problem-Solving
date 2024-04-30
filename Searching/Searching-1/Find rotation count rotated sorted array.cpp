#include <bits/stdc++.h>
using namespace std;
bool ispossible(int d, int s, vector<int> &st)
{
    for (int i = 0; i < st.size(); i += d)
    {
        int j = i;
        int sum = 0;
        while (j < st.size() && j < i + d)
            sum += st[j++];
        if (sum > s)
            return false;
    }
    return true;
}
int main()
{
    // your code goes here
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 1, h = n, ans = -1;
    while (l <= h)
    {
        int m = l + (h - l) / 2;
        if (ispossible(m, s, a))
        {
            ans = m;
            l = m + 1;
        }
        else
            h = m - 1;
    }
    cout << ans << endl;
    return 0;
}