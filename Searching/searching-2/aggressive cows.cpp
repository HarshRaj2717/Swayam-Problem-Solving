//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool check(int n, int k, vector<int> &stalls, int m){
        int i = 0;
        k--;
        for(int j = 0; j < stalls.size(); j++){
            if((stalls[j] - stalls[i]) >= m){
                k--;
                i = j;
            }
        }
        return (k <= 0);
    }

    int solve(int n, int k, vector<int> &stalls) {
        // Write your code here
        sort(stalls.begin(), stalls.end());
        int s = 0;
        int e = 1e9;
        int m = s + (e - s) / 2;
        while(s <= e){
            bool temp = check(n, k, stalls, m);
            if(temp) s = m + 1;
            else e = m - 1;
            m = s + (e - s) / 2;
        }
        return e;
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends