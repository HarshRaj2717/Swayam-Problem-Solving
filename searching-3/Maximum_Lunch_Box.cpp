#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> mp;

bool ispossible(int m, int a)
{
	int c = 0;
	for (auto it : mp)
	{
		int f = (it.second / m);
		c += f;
		if (c >= a)
			return true;
	}
	return false;
}

int main()
{
	// your code goes here
	int n;
	cin >> n;
	vector<int> b(n);
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		mp[b[i]]++;
	}
	int a;
	cin >> a;
	int l = 1, h = b.size() / a, ans = -1;
	while (l <= h)
	{
		int m = l + (h - l) / 2;
		if (ispossible(m, a))
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