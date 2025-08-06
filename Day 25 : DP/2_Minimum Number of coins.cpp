// https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1

// can use DP --> But greedy will work better here 
// User function Template for C++

/*
The greedy approach works optimally for Indian currency denominations because of their design. However, 
it does not work for arbitrary denominations. This question passes because it is specifically designed to work with the greedy algorithm.
*/

// TC == SC == O(N)
class Solution {
  public:
    vector<int> minPartition(int N) {
         // Denominations of Indian currency in decreasing order
        vector<int> denominations = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        
        // Result list to store the coins/notes
        vector<int> result;
        
        // Iterate through each denomination
        for (int coin : denominations) {
            // Subtract the denomination from N as many times as possible
            while (N >= coin) {
                N -= coin;
                result.push_back(coin);
            }
        }
        
        return result;
        
    }
};



/*
Why the Greedy Approach Works for Indian Currency:
Multiples of Smaller Denominations:
Each larger denomination in Indian currency is a multiple of smaller denominations. For example:

5 is a multiple of 1 and 2.
10 is a multiple of 1, 2, and 5.
20 is a multiple of 1, 2, 5, and 10.
This ensures that using the largest possible denomination at each step guarantees the minimum number of coins/notes.
Optimal Substructure:
The problem can be broken down into subproblems where the greedy choice (using the largest denomination) leads to the globally optimal solution.

Examples Where Greedy Works:

For N = 43, the greedy approach gives 20 + 20 + 2 + 1 (4 coins/notes), which is optimal.
For N = 1000, the greedy approach gives 500 + 500 (2 notes), which is optimal.
Why the Greedy Approach Doesn't Work in General Cases:
Non-Multiple Denominations:
If the denominations are not multiples of each other (e.g., coins = [1, 3, 4]), the greedy approach fails.

Example: For N = 6, the greedy approach gives 4 + 1 + 1 (3 coins), but the optimal solution is 3 + 3 (2 coins).
Edge Cases:
The greedy approach may fail if the denominations are not properly structured, or if N cannot be made using the given coins.
*/



