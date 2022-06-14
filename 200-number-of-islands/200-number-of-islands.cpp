class Solution {
public:
    int count = 0;
    vector<vector<bool>> vis;
    vector<vector<char>> gr;
    int row[4] = {-1,0,0,1};
    int col[4] = {0,1,-1,0};
    
    void helper(int x, int y, int n, int m){
        vis[x][y] = true;
        for(int i = 0; i < 4; i++){
            int newx = row[i] + x;
            int newy = col[i] + y;
            if(newx >= 0 && newx < n && newy >= 0 && newy < m){
                if(!vis[newx][newy] && gr[newx][newy] == '1'){
                    vis[newx][newy] = true;
                    helper(newx, newy, n, m);
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        gr = grid;
        int n = grid.size();
        int m = grid[0].size();
        vis.resize(n + 1, vector<bool>(m + 1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    vis[i][j] = true;
                    count++;
                    helper(i,j,n,m);
                }
            }
        }
        return count;
    }
};