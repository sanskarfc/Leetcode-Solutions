class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int n = a.length();
        int m = b.length();
        int dp[n + 1][m + 1];
        string s;
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int i = 0; i <= m; i++) dp[0][i] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(a[i - 1] == b[j - 1])  dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        while(n != 0 and m != 0){
            if(a[n - 1] == b[m - 1]) s.push_back(a[n - 1]), n --, m --;
            else{
                if(dp[n][m - 1] > dp[n - 1][m]){
                    s.push_back(b[m - 1]);
                    m --;
                }
                else{
                    s.push_back(a[n - 1]);
                    n --;
                }
            }
        }
        while(n != 0){
            s.push_back(a[n - 1]);
            n--;
        }
        while(m != 0){
            s.push_back(b[m - 1]);
            m--;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};