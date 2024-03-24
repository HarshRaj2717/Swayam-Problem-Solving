#include <bits/stdc++.h>
using namespace std;
int lcm(int a, int b)
{
	return (a * b) / __gcd(a, b);
}
int main()
{
	// your code goes here
	int l = 1, r = INT_MAX, a, b, c, n;
	cin >> a >> b >> c >> n;
	while (l <= r)
	{
		int m = l + (r - l) / 2;
		int n1 = (m / a);
		n1 += (m / b);
		n1 += (m / c);
		int aa = lcm(a, b), bb = lcm(b, c), cc = lcm(a, c), abc = lcm(aa, c);
		n1 -= (m / aa);
		n1 -= (m / bb);
		n1 -= (m / cc);
		n1 += (m / abc);
		if (n1 == n)
		{
			cout << m << endl;
			return 0;
		}
		if (n1 < n)
			l = m + 1;
		else
			r = m - 1;
	}
	return 0;
}
