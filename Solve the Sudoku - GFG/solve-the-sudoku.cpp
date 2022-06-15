// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    
    // isSafeAllocation
    bool isSafeAllocation(int num, int x, int y, int grid[N][N]){
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
    
    bool check(int grid[N][N]){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(grid[i][j] == 0) return false;
            }
        }
        
        return true;
    }
    
    bool SolveSudoku(int grid[N][N])  { 
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(grid[i][j] != 0) continue;
                for(int num = 1; num <= 9; num++){
                    if(isSafeAllocation(num, i, j, grid)){
                        grid[i][j] = num;
                        if(SolveSudoku(grid)) return true;
                        grid[i][j] = 0;
                    }
                }
                return false;
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) {
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout << grid[i][j] << " ";
            }
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends