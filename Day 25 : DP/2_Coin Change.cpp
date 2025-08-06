// Link --> https://leetcode.com/problems/coin-change/description/

// Coin change(Leetcode)   or  Minimum number of coins to make a Amount(GFG)   or minimum elements(codeStudio)


// Greedy Approach Fails:
//For example, if coins = [1, 3, 4] and amount = 6, the greedy approach (always taking the largest coin) would give 4 + 1 + 1 (3 coins),
//but the optimal solution is 3 + 3 (2 coins).

// Cases --> 1. possible --> return value
//           2. not possible return -1
//           3. amount =0 return 0


//RECURSION --> TLE
class Solution {  
public:  
    // Function to solve the coin change problem recursively  
    int solve(vector<int> &coins, int x) {  

        // Base case: If the target amount `x` is 0, no coins are needed.  
        if (x == 0) return 0;  

        // Base case: If the target amount `x` is negative, it's invalid. Return `INT_MAX`.  
        if (x < 0) return INT_MAX;  

        // Initialize `mini` to `INT_MAX` to track the minimum number of coins needed.  
        int mini = INT_MAX;  

        // Iterate through each coin in the list of coins.  
        for (int i = 0; i < coins.size(); i++) {  

            // Recursively call `solve` to find the number of coins needed for `x - coins[i]`.  
            int ans = solve(coins, x - coins[i]);  

            // If the result is valid (not `INT_MAX`), update `mini` with the minimum value.  
            if (ans != INT_MAX)  
                mini = min(mini, 1 + ans);  // Add 1 coin to the result.  
        }  

        // Return the minimum number of coins needed for `x`.  
        return mini;  
    }  

    // Function to find the minimum number of coins needed to make the `amount`.  
    int coinChange(vector<int>& coins, int amount) {  

        // Call the `solve` function to compute the minimum number of coins.  
        int ans = solve(coins, amount);  

        // If the result is `INT_MAX`, it means the `amount` cannot be made with the given coins. Return `-1`.  
        if (ans == INT_MAX) return -1;  

        // Return the minimum number of coins needed.  
        return ans;  
    }  
};



// MEMOIZATION
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(vector<int>& coins, int x, vector<int>& dp) {
        if (x == 0) return 0;
        if (x < 0) return INT_MAX;
        if (dp[x] != -1) return dp[x];

        int mini = INT_MAX;
        for (int coin : coins) {
            int ans = solve(coins, x - coin, dp);
          
            if (ans != INT_MAX)mini = min(mini, 1 + ans);
        }

        dp[x] = mini;//cache
        return dp[x];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int ans = solve(coins, amount, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};
