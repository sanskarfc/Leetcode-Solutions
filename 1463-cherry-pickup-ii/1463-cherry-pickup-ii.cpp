class Solution {
public:
    int dy[3] = {-1,0,1};
    vector<vector<vector<int>>> dp;
    vector<vector<int>> grid;
    int n, m;
    
    int helper(int row, int col1, int col2){
        if(row >= n || col1 < 0 || col2 < 0 || col1 >= m || col2 >= m) return 0;
        if(dp[row][col1][col2] != -1) return dp[row][col1][col2];
        int maxm = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int col1_new = col1 + dy[i];
                int col2_new = col2 + dy[j];
                if(col1_new == col2_new) continue;
                maxm = max(maxm, grid[row][col1] + grid[row][col2] + helper(row + 1, col1_new, col2_new));
            }
        }
        return dp[row][col1][col2] = maxm;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        dp.resize(n + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, -1)));
        return helper(0, 0, m - 1);
    }
};