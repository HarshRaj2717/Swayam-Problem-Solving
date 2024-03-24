#include <bits/stdc++.h>
using namespace std;
int solve(int n, vector<int> &ar)
{
	int l = 0, h = ar.size() - 1, ans = ar.size();
	while (l <= h)
	{
		int m = l + (h - l) / 2;
		if (ar[m] >= n)
		{
			ans = m;
			h = m - 1;
		}
		else
			l = m + 1;
	}
	return ans;
}
int main()
{
	int n, q;
	cin >> n >> q;
	vector<int> ar(n);
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	sort(ar.begin(), ar.end());
	for (int i = 0; i < q; i++)
	{
		int t;
		cin >> t;
		cout << n - solve(t, ar) << endl;
	}
	return 0;
}