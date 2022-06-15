class Solution {
public:
    int n;
    vector<int> dp;
    vector<int> vis;
    string s;
    int helper(int ind){
        if(ind == n) return 1;
        if(vis[ind]) return dp[ind];
        vis[ind] = true;
        if(ind == n - 1){
            int a = 0;    
            int ans = 0;
            a = s[ind] - '0';
            if(a >= 1 && a <= 9)
                ans = helper(ind + 1);
            return dp[ind] = ans;
        }
        else{
            int a = 0;
            int b = 0;
            int ans1 = 0;
            int ans2 = 0;
            a = s[ind] - '0';
            b = (s[ind] - '0') * 10 + (s[ind + 1] - '0');
            if(b >= 10 && b <= 26) 
                ans2 = helper(ind + 2);
            if(a >= 1 && a <= 9)
                ans1 = helper(ind + 1);
            return dp[ind] = ans1 + ans2;
        }
    }
    int numDecodings(string ss) {
        // state of the dp --> current index
        s = ss;
        n = s.length();
        vis.resize(n + 1, false);
        dp.resize(n + 1);
        return helper(0);
    }
};