class Solution {
public:
    int row[4] = {0,0,1,-1};
    int col[4] = {1,-1,0,0};
    vector<vector<int>> dis;
    int n, m;
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dis.resize(n + 1, vector<int>(m + 1));
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    dis[i][j] = 0;
                }
                else dis[i][j] = INT_MAX;
            }
        }
        int maxm = 0;
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            for(int i = 0; i < 4; i++){
                int newx = x + row[i];
                int newy = y + col[i];
                if(newx >= 0 && newx < n && newy < m && newy >= 0 && grid[newx][newy] == 1){
                    grid[newx][newy] = 0;
                    dis[newx][newy] = min(dis[newx][newy], dis[x][y] + 1);
                    maxm = max(maxm, dis[newx][newy]);
                    q.push({newx,newy});
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }    
        }
        return maxm;
        
    }
};