class Solution {
public:
    int longestCommonSubsequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(word1[i] == word2[j]){
                    if(i - 1 >= 0 && j - 1 >= 0){
                        dp[i][j] = 1 + dp[i - 1][j - 1];    
                    }
                    else{
                        dp[i][j] = 1;   
                    }
                }
                else{
                    if(i - 1 >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                    if(j - 1 >= 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                }
            }    
        }
        return dp[n - 1][m - 1];
    }
};