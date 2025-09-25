
// Link --> https://leetcode.com/problems/word-search/description/?envType=problem-list-v2&envId=depth-first-search&
class Solution {
public:

    bool checkWord(vector<vector<char>>& board, string word,int i ,int j,int len){

        if(len==word.size()){
            return true;
        }

        if(i>=0&&j>=0&&i<board.size()&&j<board[0].size()&&board[i][j]==word[len]){

                board[i][j] = '*' ;
                bool right = checkWord(board,word,i+1,j,len+1);
                bool down = checkWord(board,word,i,j+1,len+1);
                bool  up = checkWord(board,word,i-1,j,len+1);
                bool  left = checkWord(board,word,i,j-1,len+1);
                board[i][j] = word[len];
                
                if(up||down||left||right) return true;
        }
        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j =0; j<board[0].size(); j++){    
                if(checkWord(board,word,i, j, 0))
                    return true;
            }
        }

        return false;
    }
};
