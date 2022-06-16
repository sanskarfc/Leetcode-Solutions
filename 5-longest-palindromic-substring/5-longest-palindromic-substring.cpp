class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int len = 1;
        for(int i = 0; i < n; i++){
            dp[i][i] = true;   
        }
        for(int i = 0; i < n - 1; i++){
            if(s[i] == s[i + 1]){
                dp[i][i + 1] = true;
                len = 2;
            }
        }
        
        for(int l = 3; l <= n; l++){
            for(int i = 0; i < n; i++){
                int j = i + l - 1;
                if(j >= n) continue;
                dp[i][j] = (dp[i + 1][j - 1] & (s[i] == s[j]));
                if(dp[i][j]){
                    len = max(len, j - i + 1);
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(i + len - 1 < n){
                if(dp[i][i + len - 1]){
                    string ans = "";
                    for(int j = i; j <= i + len - 1; j++){
                        ans += s[j];
                    }
                    return ans;
                }
            }
        }
        return "yo";
    }
};