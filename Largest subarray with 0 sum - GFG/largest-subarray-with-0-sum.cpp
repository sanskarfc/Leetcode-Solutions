// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n){  
        // largest subarray with sum = 0
        
        // the naive appraoch would be O(n ^ 2)
        // this appraoch is O(n)
        int sum = 0;
        map<int,int> pref;
        pref[0] = 0;
        int maxm = 0;
        for(int i = 0; i < n; i++){
            sum += A[i];
            if(sum == 0){
                maxm = max(maxm, i + 1);
            }
            if(pref[sum] != 0) maxm = max(maxm, i - pref[sum] + 1);
            else pref[sum] = i + 1;
        }
        return maxm;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends