class Solution {
public:
    bool check(vector<vector<char>> &board, int i, int j){
        int row = i - i%3;
        int column = j - j%3;
        char val = board[i][j];
        int count = 0;
        for(int x=0; x<9; x++){
            if(board[x][j] == val) count++;
            if(board[i][x] == val) count++;
        }
        if(count > 2) return false;
        count = 0;
        for(int x=0; x<3; x++){
            for(int y=0; y<3; y++){
                if(board[row+x][column+y] == val) {
                    count++;
                }
            }
        }
        if(count > 1) return false;
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    bool yo = check(board, i, j);
                    if(!yo){
                        // cout << "i: " << i << endl;
                        // cout << "j: " << j << endl;
                        // cout << board[i][j] << endl;
                        // cout << endl;
                        return false;
                    }
                }
            }
        }
        return true;
    }
};