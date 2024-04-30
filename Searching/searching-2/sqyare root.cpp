#include <bits/stdc++.h>

using namespace std;

int solver(int x)
{
    int s = 0;
    int e = 1e9;
    while (s <= e)
    {
        int m = (s + e) / 2;
        if (m * m > x)
        {
            e = m - 1;
        }
        else
        {
            if ((m + 1) * (m + 1) > x)
                return m;
            s = m + 1;
        }
    }
    return s;
}

int main()
{
    int n;
    cin >> n;
    cout << solver(n) << endl;
    return 0;
}
