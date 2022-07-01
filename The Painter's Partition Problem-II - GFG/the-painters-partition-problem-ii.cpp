// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:

    static bool check(long long int mid, vector<int>&a, int M){
        int sum = 0;
        int grp = 1;
        for(int i = 0; i < (int)a.size(); i++){
            if(sum + a[i] > (int)mid){
                if(a[i] > mid) return false;
                sum = a[i];
                grp++;
            }
            else{
                sum += a[i];
            }
        }
        if(grp > M) return false;
        return true;
    }
    
    long long minTime(int A[], int N, int M){
        vector<int> a(N);
        for(int i = 0; i < N; i++) a[i] = A[i];
        long long int lo = 1;
        long long int hi = INT_MAX - 500;
        while(hi - lo > 5){
            long long int mid = lo + (hi - lo)/2;
            // cout << "Mid: " << mid << endl;
            if(check(mid, a, M)) hi = mid;
            else lo = mid + 1;
        }
        int i;
        for(i = lo; i <= hi; i++){
            if(check(i, a, M)) return i;
        }
        return 0; // we won't ever reach here
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends