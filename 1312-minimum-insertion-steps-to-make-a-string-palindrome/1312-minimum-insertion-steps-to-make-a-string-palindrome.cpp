class Solution {
public:
    vector<vector<int>> dp;
    string s;
    
    int helper(int i, int j){
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]){
            return dp[i][j] = 2 + helper(i + 1, j - 1);
        }
        else{
            return dp[i][j] = max(helper(i + 1, j), helper(i, j - 1));
        }
    }
    
    int minInsertions(string ss) {
        s = ss;
        int n = s.length();
        dp.resize(n + 1, vector<int>(n + 1, -1));
        int lis = helper(0, n - 1);
        return (n - lis);
    }
};