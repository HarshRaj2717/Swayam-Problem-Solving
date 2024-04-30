#include <bits/stdc++.h>

using namespace std;

bool check(int mid, string &s, string &t, int maxCost)
{
    int cost = 0;
    for (int i = 0; i < mid; i++)
    {
        cost += abs(s[i] - t[i]);
    }
    if (cost <= maxCost)
        return true;
    int left = 0;
    for (int i = mid; i < s.size(); i++)
    {
        cost += abs(s[i] - t[i]);
        cost -= abs(s[left] - t[left]);
        left++;
        if (cost <= maxCost)
            return true;
    }
    return false;
}

int solver(string s, string t, int maxCost)
{
    int lo = 0;
    int hi = s.size();
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid, s, t, maxCost))
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    if (check(lo, s, t, maxCost))
        return lo;
    else
        return lo - 1;
}

int main()
{
    string s;
    string t;
    int maxCost;
    cin >> s >> t;
    cin >> maxCost;
    cout << solver(s, t, maxCost) << endl;
    return 0;
}