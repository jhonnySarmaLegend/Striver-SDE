// LINK --> https://leetcode.com/problems/number-of-islands/description/

// DFS

class Solution {
public:
    void dfs(vector<vector<char>>& grid,int m , int n ,  int i , int j ){
        if(i<0 || j < 0 || i >m-1 || j>n-1 || grid[i][j] == '0' ||grid[i][j] == 'V'){
            return ; 
        }
        grid[i][j] = 'V' ;// marked visited

        dfs(grid, m , n , i+1 , j);
        dfs(grid, m , n , i-1 , j);
        dfs(grid, m , n , i , j+1);
        dfs(grid, m , n , i , j-1);

    }




    int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    
    int count = 0 ; 
    for(int i = 0 ; i < m ; i ++ ){
        for(int j = 0 ; j < n ; j ++){
            if(grid[i][j] == '1'){
              count ++ ; 
              dfs(grid, m, n , i , j); 
            }
        }
    }
    return count ; 

    }
};
