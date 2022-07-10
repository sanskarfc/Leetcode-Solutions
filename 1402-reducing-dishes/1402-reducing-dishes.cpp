class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        vector<int> col(n + 1, INT_MIN);
        int maxm = 0;
        col[0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= i + 1; j++){
                dp[i][j] = col[j - 1] + j*satisfaction[i];
                maxm = max(maxm, dp[i][j]);
            }
            for(int j = 1; j <= i + 1; j++) col[j] = max(col[j], dp[i][j]);
        }
        return maxm;
    }
};