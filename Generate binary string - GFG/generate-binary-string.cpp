// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
	public:
	    vector<string> ans;
	    string temp;
	    string s;
	    int n;
	    
	    void helper(int ind){
	        if(ind == n){
	            ans.push_back(temp);
	            return;
	        }
	        if(s[ind] == '?'){
	            string temp2 = temp;
	            temp += '0';
	            helper(ind + 1);
	            temp = temp2;
	            temp += '1';
	            helper(ind + 1);
	        }
	        else{
	            temp += s[ind];
	            helper(ind + 1);
	        }
	    }
	    
		vector<string> generate_binary_string(string ss){
		    s = ss;
		    n = s.length();
		    helper(0);
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string s;
	    cin >> s;
	    Solution ob;
	    vector<string> ans = ob.generate_binary_string(s);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}  // } Driver Code Ends