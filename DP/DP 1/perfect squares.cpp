class Solution {
    int recur(int n)
    {
        if(n == 0)
            return 0;
        if (n < 0)
            return INT_MAX;

        int ans = INT_MAX;
        for (int i = 1; i * i <= n; i++)
        {
            ans = min(ans, 1 + recur(n - i * i));
        }

        return ans;
    }

    vector<int> mem;
    int memo(int n)
    {
        if(n == 0)
            return 0;
        if (n < 0)
            return INT_MAX;
        if (mem[n - 1] != -1)
            return mem[n - 1];


        int ans = INT_MAX;
        for (int i = 1; i * i <= n; i++)
        {
            ans = min(ans, 1 + memo(n - i * i));
        }

        mem[n - 1] = ans;
        return ans;
    }

    int dp(int n)
    {
        mem = vector<int> (n+1, INT_MAX);
        mem[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                mem[i] = min(mem[i], mem[i - j * j] + 1);
            }
        }

        return mem[n];
    }
public:
    int numSquares(int n) {
        // return recur(n);

        // mem = vector<int> (n, -1);
        // return memo(n);

        return dp(n);
    }
};