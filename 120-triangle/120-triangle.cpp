class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = 0;
        int max_row = triangle.size();
        int max_col = triangle[max_row - 1].size();
        vector<vector<int>> dp(max_row + 1, vector<int>(max_col + 1, INT_MAX));
        dp[0][0] = triangle[0][0];
        for(int i = 0; i < max_row - 1; i++){
            for(int j = 0; j <= i; j++){
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + triangle[i + 1][j]);
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + triangle[i + 1][j + 1]);
            }
        }   
        int minm = INT_MAX;
        for(int i = 0; i < max_row; i++){
            minm = min(minm, dp[max_row - 1][i]);
        }
        return minm;
    }
};