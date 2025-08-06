// https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1

// can use DP --> But greedy will work better here 
// User function Template for C++


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
