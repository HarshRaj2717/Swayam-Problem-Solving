class Solution {
    int recur(const string &s, int i = 0) {
        if (i == s.size())
            return 1;
        if (s[i] == '0')
            return 0;

        int ans = 0;
        ans += recur(s, i + 1);
        if (i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
            ans += recur(s, i + 2);
        return ans;
    }

    vector<int> mem;
    int memo(const string &s, int i = 0) {
        if (i == s.size())
            return 1;
        if (s[i] == '0')
            return 0;
        if (mem[i] != -1)
            return mem[i];

        int ans = 0;
        ans += memo(s, i + 1);
        if (i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
            ans += memo(s, i + 2);
        mem[i] = ans;
        return ans;
    }

    int dp(const string &s, int i = 0) {
        mem = vector<int> (s.size() + 1, 0);
        // mem[i] => number of ways from i->n-1 (inclusive)
        // mem[s.size()] => reaching here means full string completed, hence 1
        mem[s.size() - 1] = (s[s.size() - 1] != '0');
        mem[s.size()] = 1;

        for (int i = s.size() - 2; i >= 0; i--) {
            if (s[i] == '0')
                continue;
            mem[i] += mem[i+1];
            if (i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
                mem[i] += mem[i + 2];
        }

        return mem[0];
    }
public:
    int numDecodings(string s) {
        if (s.size() == 0)
            return 0;
        // return recur(s);

        // mem = vector<int> (s.size(), -1);
        // return memo(s);

        return dp(s);
    }
};