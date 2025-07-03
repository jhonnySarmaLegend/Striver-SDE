// Link --> https://www.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1

// Similar to Fibonacci 


// Recursion - TLE
 int countWays(int n) {
        // your code here
        if(n<=1)return 1;
        
        return countWays(n-1) + countWays(n-2);
    }

//D.P.

//1. Memoization
// Helper function for memoization
int countWaysMemoHelper(int n, vector<int>& dp) {
    // Base cases
    if (n == 0 || n == 1) {
        return 1; 
    }

    // If the result for 'n' is already computed, return it from dp array
    if (dp[n] != -1) {
        return dp[n];
    }

    // Compute the result recursively and store it in dp array before returning
    dp[n] = countWaysMemoHelper(n - 1, dp) + countWaysMemoHelper(n - 2, dp);
    return dp[n];
}

// Main function for countWays using Memoization
int countWaysMemo(int n) {
    // Initialize dp array with -1 (or any value indicating not computed)
    // Size n+1 to handle up to F(n)
    vector<int> dp(n + 1, -1); 
    return countWaysMemoHelper(n, dp);
}

//2.Tabulation
int countWaysTabulation(int n) {
    // Handle edge cases for n < 0 if necessary
    if (n < 0) {
        return 0; 
    }
    if (n <= 1) {
        return 1; // Base cases: F(0) = 1, F(1) = 1
    }

    // Create dp array of size n+1
    vector<int> dp(n + 1);

    // Initialize base cases in the dp array
    dp[0] = 1; // F(0)
    dp[1] = 1; // F(1)

    // Fill the dp array iteratively from 2 up to n
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // The result for n is now stored in dp[n]
    return dp[n];
}





/*   TRICKS

--> Try to represent the problem in terms of index
--> Do all possible stuffs on that index according to the problem statements
--> If question says , count all the ways - sum all stuffs
                      find minimum - min of all stuffs
                      find maximum - max of all stuffs


*/
