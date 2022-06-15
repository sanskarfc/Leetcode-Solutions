class Solution {
public:
    
    static const int N = 9;
    int grid[N][N];
    // isSafeAllocation
    bool isSafeAllocation(char num, int x, int y, vector<vector<char>> &grid){
        for(int i = 0; i < N; i++){
            if(grid[x][i] == num) return false;
            if(grid[i][y] == num) return false;
        }
        int rowstart = 3*(x/3);
        int colstart = 3*(y/3);
        
        for (int i = rowstart; i < rowstart + 3; i ++) {
            for (int j = colstart; j < colstart + 3; j ++) {
                if (i != x && j != y && grid[i][j] == num) return false;
            }
        }
        return true;
    }
    
    bool SolveSudoku(vector<vector<char>> &grid)  { 
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(grid[i][j] != '.') continue;
                for(char num = '1'; num <= '9'; num++){
                    if(isSafeAllocation(num, i, j, grid)){
                        grid[i][j] = num;
                        if(SolveSudoku(grid)) return true;
                        grid[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& grid) {
        SolveSudoku(grid);
    }
};