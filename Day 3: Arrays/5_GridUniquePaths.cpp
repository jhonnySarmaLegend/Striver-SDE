// variation 2 --> using dp --> with obstacle--> https://leetcode.com/problems/unique-paths-ii/description/


/*
   Question Link --> https://leetcode.com/problems/unique-paths/description/  --> No obstacle
*/

/*OPTIMAL --> NcR*/
int uniquePaths(int m, int n) {
        int N = n + m - 2; // Total steps
        int r = min(n-1,m-1);
   // int r = n - 1;     // The number of right movements (can use m - 1 as well)

        // Ensure r is not larger than N-r, so we compute C(N, r) = C(N, N - r)
       // if (r > N - r) {
       //     r = N - r;
      //  }

        long long res = 1; // Use long long to prevent overflow
        
        // Calculate C(N, r) = N! / (r! * (N - r)!)
        for (int i = 0; i < r; i++) {
            res = res * (N - i);
            res = res / (i + 1);
        }

        return (int)res; // Convert to int before returning
 
    }
//BRUTE FORCE - RECURSION 
// T.C. = Exponential

class Solution {
public:
int countPaths(int i, int j, int m, int n) {
        // If the robot reaches the bottom-right corner, there's one unique path
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        
        // If the robot goes out of bounds, there's no valid path
        if (i >= m || j >= n) {
            return 0;
        }
        
        // Recur for the cell below (down) and the cell to the right
        int down_paths = countPaths(i + 1, j, m, n);
        int right_paths = countPaths(i, j + 1, m, n);
        return down_paths + right_paths;
    }
    int uniquePaths(int m, int n) {
        return countPaths(0, 0, m, n);
    }
};



// BETTER SOLUTION - D.P. Memoization
// T.C. = O(MxN) ,S.C. = O(MxN)

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a memoization table with -1 as unvisited state
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countPaths(0, 0, m, n, dp);
    }

private:
    int countPaths(int i, int j, int m, int n, vector<vector<int>>& dp) {
        // Base case: if we've reached the bottom-right corner
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        
        // If the robot goes out of bounds, there's no valid path
        if (i >= m || j >= n) {
            return 0;
        }
        
        // Check if the value is already computed in dp
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        // Recursively count the paths from the cell below and to the right
        dp[i][j] = countPaths(i + 1, j, m, n, dp) + countPaths(i, j + 1, m, n, dp);
        return dp[i][j];
    }
};


// OPTIMAL - Combination
// T.C. = O(M-1) or O(N-1)
int uniquePaths(int m, int n) {
            int N = n + m - 2;
            int r = m - 1; 
            double res = 1;
            //Calculating Ncr
            for (int i = 1; i <= r; i++)
                res = res * (N - r + i) / i;
            return (int)res;
    }



/*

   Total Paths to travel = (m-1) + (n-1) = m+n-2
   r = m - 1 of these slots to be downward moves  = Ncr   T.C. = O(M-1) 
   or
   r = n - 1 of these slots to be rightward moves = Ncr   T.C. = O(N-1)
   Since, N=n+m-2 so r= m-1 or n-1 , Ncr will give same values



   Imagine you are navigating a grid from the top-left corner to the bottom-right corner. You are only allowed to move either down or right. The core idea is to realize that every unique path consists of a fixed number of down moves and a fixed number of right moves.

To reach the bottom row (row m-1 from row 0), you must make exactly m-1 downward moves.
To reach the rightmost column (column n-1 from column 0), you must make exactly n-1 rightward moves.
Therefore, any path from the start to the end will consist of a total of (m-1) + (n-1) = m + n - 2 moves. The problem then boils down to: in a sequence of m + n - 2 moves, how many ways can we choose the positions for the m-1 downward moves (or equivalently, the n-1 rightward moves)?

This is a classic combinatorial problem. If we have a total of N = m + n - 2 slots (representing the moves), we need to choose r = m - 1 of these slots to be downward moves. The remaining N - r = (m + n - 2) - (m - 1) = n - 1 slots will automatically be rightward moves.

The number of ways to choose r items from a set of N items (without regard to order) is given by the binomial coefficient:

( 
r
N
​
 )= 
r!(N−r)!
N!
​

*/






