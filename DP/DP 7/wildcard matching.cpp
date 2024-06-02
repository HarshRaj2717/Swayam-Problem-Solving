class Solution {
    bool recur(string &s, string &p, int i = 0, int j = 0)
    {
        if (i == s.size() && j == p.size())
            return true;
        if (j == p.size())
            return false;

        if (p[j] == '*')
        {
            for (int ii = i; ii <= s.size(); ii++)
            {
                if (recur(s, p, ii, j + 1))
                    return true;
            }
        }
        else if (p[j] == '?' || p[j] == s[i])
        {
            return recur(s, p, i + 1, j + 1);
        }

        return false;
    }

    vector<vector<int>> mem;
    bool memo(string &s, string &p, int i = 0, int j = 0)
    {
        if (i == s.size() && j == p.size())
            return true;
        else if (j == p.size())
            return false;

        if (mem[i][j] != -1)
            return mem[i][j];

        bool res = false;

        if (p[j] == '*')
        {
            for (int ii = i; ii <= s.size(); ii++)
            {
                res = (res || memo(s, p, ii, j + 1));
            }
        }
        else if (i < s.size() && p[j] == '?' || p[j] == s[i])
        {
            res = (res || memo(s, p, i + 1, j + 1));
        }

        mem[i][j] = res;
        return res;
    }

    bool tabulation(string &s, string &p)
    {
        vector<vector<bool>> dp(s.size() + 1, vector<bool> (p.size() + 1, false));

        dp[0][0] = true;
        for (int j = 1; j <= p.size(); j++)
        {
            dp[0][j] = (dp[0][j-1] && (p[j-1] == '*'));
        }

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= p.size(); j++)
            {
                if (p[j-1] == '*')
                {
                    for (int ii = i; ii >= 0 && dp[i][j] == false; ii--)
                    {
                        dp[i][j] = dp[i][j] || dp[ii][j-1];
                    }
                }
                else if (p[j-1] == '?' || p[j-1] == s[i-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }

        return dp[s.size()][p.size()];
    }
public:
    bool isMatch(string s, string p) {
        // return recur(s, p);

        // mem = vector<vector<int>> (s.size() + 1, vector<int> (p.size(), -1));
        // return memo(s, p);

        return tabulation(s, p);
    }
};