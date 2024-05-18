class Solution {
    int MOD = 1e9 + 7;

    long long recur(const string &s, int i = 0) {
        if (i == s.size())
            return 1;
        if (s[i] == '0')
            return 0;

        long long ans = 0;

        if (s[i] == '*') {
            ans += (recur(s, i + 1) * 9) % MOD;
            if (i + 1 < s.size()) {
                int t = (recur(s, i + 2) * (s[i + 1] >= '0' && s[i + 1] <= '6' ? 2 : 1)) % MOD;
                if (s[i+1] == '*')
                    ans += t * (26 - 9 - 2);
                else
                    ans += t;
            }
        }
        else {
            ans += recur(s, i + 1) % MOD;
            if (i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
                if (s[i+1] == '*')
                    ans += (recur(s, i + 2) * (s[i] == '1' ? 9 : 6)) % MOD;
                else
                    ans += recur(s, i + 2) % MOD;
            }
        }

        return ans % MOD;
    }

    vector<long long> mem;
    long long memo(const string &s, int i = 0) {
        if (i == s.size())
            return 1;
        if (s[i] == '0')
            return 0;
        if (mem[i] != -1)
            return mem[i];

        long long ans = 0;

        if (s[i] == '*') {
            ans += (memo(s, i + 1) * 9) % MOD;
            if (i + 1 < s.size()) {
                long long t = (memo(s, i + 2) * (s[i + 1] >= '0' && s[i + 1] <= '6' ? 2 : 1)) % MOD;
                if (s[i+1] == '*')
                    ans = (ans + t * (26 - 9 - 2)) % MOD;
                else
                    ans = (ans + t) % MOD;
            }
        }
        else {
            ans += memo(s, i + 1) % MOD;
            if (i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
                if (s[i+1] == '*')
                    ans = (ans % MOD + (memo(s, i + 2) * (s[i] == '1' ? 9 : 6)) % MOD) % MOD;
                else
                    ans = (ans % MOD + memo(s, i + 2) % MOD) % MOD;
            }
        }

        mem[i] = ans % MOD;
        return ans % MOD;
    }

    int dp(const string &s, int i = 0) {
        mem = vector<long long> (s.size() + 1, 0);
        // mem[i] => number of ways from i->n-1 (inclusive)
        // mem[s.size()] => reaching here means full string completed, hence 1
        mem[s.size() - 1] = (s[s.size() - 1] == '*' ? 9 : s[s.size() - 1] != '0');
        mem[s.size()] = 1;

        for (int i = s.size() - 2; i >= 0; i--) {
            if (s[i] == '0')
                continue;
            if (s[i] == '*') {
                mem[i] = (mem[i] + (mem[i + 1] * 9) % MOD) % MOD;
                if (i + 1 < s.size()) {
                    long long t = (mem[i + 2] * (s[i + 1] >= '0' && s[i + 1] <= '6' ? 2 : 1)) % MOD;
                    if (s[i+1] == '*')
                        mem[i] = (mem[i] + t * (26 - 9 - 2) % MOD) % MOD;
                    else
                        mem[i] = (mem[i] + t) % MOD;
                }
                continue;
            }

            mem[i] = (mem[i] + mem[i+1]) % MOD;
            if (i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
                if (s[i+1] == '*')
                    mem[i] = (mem[i] + (mem[i + 2] * (s[i] == '1' ? 9 : 6)) % MOD) % MOD;
                else
                    mem[i] = (mem[i] + mem[i + 2]) % MOD;
            }
        }

        return mem[0];
    }
public:
    int numDecodings(string s) {
        if (s.size() == 0)
            return 0;
        // return recur(s);

        // mem = vector<long long> (s.size(), -1);
        // return memo(s);

        return dp(s);
    }
};