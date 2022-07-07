// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCut(int n, int m){
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
        
        
        // base cases
        dp[0][0] = 0;
        for(int i = 1; i <= m; i++) dp[1][i] = i;
        for(int i = 1; i <= n; i++) dp[i][1] = i;
        for(int i = 1; i <= min(n,m); i++) dp[i][i] = 1;
        
        for(int i = 2; i <= n; i++){
            for(int j = 2; j <= m; j++){
                int minm = dp[i][j];
                for(int x = 1; x <= i/2; x++){
                    minm = min(minm, dp[x][j] + dp[i - x][j]);
                }
                for(int y = 1; y <= j/2; y++){
                    minm = min(minm, dp[i][y] + dp[i][j - y]);
                }
                dp[i][j] = minm;
            }
        }
        
        return dp[n][m];
	}
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

	    

	    Solution ob;
	    cout << ob.minCut(m, n) << "\n";

	     
    }
    return 0;
}
  // } Driver Code Ends