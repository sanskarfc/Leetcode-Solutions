class Solution {
public:
    int res = 0;
    int siz = 1;
    int n, m;
    
    void dfs(vector<vector<int>>& grid, int x, int y, int count) {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == -1) return;
        
        if (grid[x][y] == 2) {
            if(siz == count) res++; 
            return;
        }
        
        grid[x][y] = -1;
        
        dfs(grid, x+1, y, count+1);
        dfs(grid, x-1, y, count+1);
        dfs(grid, x, y+1, count+1);
        dfs(grid, x, y-1, count+1);
        
        grid[x][y] = 0;
        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startx, starty;
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) startx = i, starty = j;
                else if (grid[i][j] == 0) siz++;
            }
        }
        
        dfs(grid, startx, starty, 0);
        return res;
    }
};