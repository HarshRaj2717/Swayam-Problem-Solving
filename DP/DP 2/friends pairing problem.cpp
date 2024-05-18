//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
    int recur(int n)
    {
        if (n < 0)
            return -1;
        if (n == 0)
            return 1;
        
        return recur(n - 1) + recur(n - 2) * (n - 1);
    }
    
    vector<long long> mem;
    int memo(int n)
    {
        if (n < 0)
            return -1;
        if (n == 0)
            return 1;
        if (mem[n] != -1)
            return mem[n];

        mem[n] = memo(n - 1) % 1000000007 + ((long long)memo(n - 2) * (n - 1)) % 1000000007;
        return mem[n] % 1000000007;
    }
    
    int dp(int n)
    {
        mem = vector<long long> (n + 1, 1);
        // dp[i] => total pairs from 0->i
        for (int i = 2; i <= n; i++)
        {
            mem[i] = mem[i-1] % 1000000007 + (mem[i-2] * (i - 1)) % 1000000007;
        }
        return mem[n];
    }
public:
    int countFriendsPairings(int n) 
    {
        if (n == 0)
            return 0;
        
        // return recur(n) % 1000000007;
        
        // mem = vector<long long> (n + 1, -1);
        // return memo(n) % 1000000007;
        
        return dp(n) % 1000000007;
    }
};    
 


//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends