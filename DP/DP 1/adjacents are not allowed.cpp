//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int recur(int &N, vector<vector<int>> &mat, int i = 0) {
        if (i >= N)
            return 0;

        return max((max(mat[0][i], mat[1][i]) + recur(N, mat, i + 2)), recur(N, mat, i + 1));
    }

    vector<int> mem;
    int memo(int &N, vector<vector<int>> &mat, int i = 0) {
        if (i >= N)
            return 0;
        if (mem[i] != -1)
            return mem[i];

        mem[i] = max((max(mat[0][i], mat[1][i]) + memo(N, mat, i + 2)), memo(N, mat, i + 1));
        return mem[i];
    }

    int dp(int &N, vector<vector<int>> &mat) {
        mem = vector<int> (N + 1, 0);
        // mem[i] => max sum that we can get from i->N-1
        // added an extra index so that we don't need to add extra checks forwhen accessing i + 2 when i == N - 2
        int i = N - 1;
        mem[i] = max(mat[0][i], mat[1][i]);
        i--;

        for (; i >= 0; i--)
        {
            mem[i] = max((max(mat[0][i], mat[1][i]) + mem[i + 2]), mem[i + 1]);
        }

        return mem[0];
    }
public:
    int maxSum(int N, vector<vector<int>> mat)
    {
        // return recur(N, mat);

        // mem = vector<int> (N, -1);
        // return memo(N, mat);

        return dp(N, mat);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> mat(2, vector<int>(N, 0));
        for(int i = 0;i < 2; i++){
            for(int j = 0; j < N; j++)
                cin>>mat[i][j];
        }
        
        Solution ob;
        cout<<ob.maxSum(N, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends