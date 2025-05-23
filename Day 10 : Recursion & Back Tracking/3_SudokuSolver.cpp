// Question Link --> https://leetcode.com/problems/sudoku-solver/description/

/*
Time Complexity: O(9(n ^ 2)), in the worst case, for each cell in the n2 board, we have 9 possible numbers.

Space Complexity: O(1), since we are refilling the given board itself, there is no extra space required, so constant space complexity.
*/
   class Solution {
public:
    bool solve(vector<vector<char>>& board){
        for(int i = 0 ;i<board.size();++i){
            for(int j = 0 ;j<board[0].size();++j){
                if(board[i][j]=='.'){
                    for(char k = '1' ;k<='9';k++){
                        if(isvalid(i,j,k,board)){
                                 board[i][j]=k;
                            if(solve(board)){
                               return true;
                            }
                        
                        else{
                            board[i][j] = '.' ;

                        }
                        }
                    }
                    return false;
                }
            }
        }return true;
    }
    bool isvalid(int r,int c ,char digit,vector<vector<char>>&board){
        for(int i = 0 ;i<9;i++){
            if(board[r][i]==digit){// //rows
                return false;
            }
          
            if(board[i][c]==digit){ //cols
                return false;
            }
            if(board[3*(r/3)+i/3][3*(c/3)+i%3]==digit){ //submatrix
                return false;
            }
        }return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        
    }
};
