// Problem : Given 2 positive natural integers, A & B.
// An integer k is good if k > 0 and (k - sumOfDigits(k)) >= B
// Find the number of good integers less than or equal to A.
// Constraints: A >= 1, B >= 1

// Linear search is simple, check output of the following python code to understand binary search's logic:
/*

def sum(n):
    res = 0
    n = str(n)
    for i in n:
        res += int(i)
    return res

i = 0
while i < 501:
    if i % 10 == 0:
        print("---")
    print(f'{i} :: {i - sum(i)}')
    i += 1

*/

#include <bits/stdc++.h>

using namespace std;

int sumOfDigits(int n)
{
    int ans = 0;
    while (n)
    {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int solver(int a, int b)
{
    int s = 1;
    int e = a / 10;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (m * 10 - sumOfDigits(m * 10) >= b)
            e = m - 1;
        else
            s = m + 1;
    }
    return a - s * 10 + 1;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << solver(a, b) << endl;
    return 0;
}
