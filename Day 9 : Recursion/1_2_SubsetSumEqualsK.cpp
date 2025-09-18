/*
  Question Id--> https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
*/

// Using Rec. O(2^n) but need to use DP --> TLE

bool helper(int ind, vector<int>& arr, int sum, int currSum) {
    // Base case: if currSum equals the desired sum
    if (currSum == sum) return true;

    // If we've gone through the array or current sum exceeds the target sum
    if (ind == arr.size() || currSum > sum) return false;

    // Pick the current element
    bool pick = helper(ind + 1, arr, sum, currSum + arr[ind]);

    // Do not pick the current element
    bool noPick = helper(ind + 1, arr, sum, currSum);

    // Return true if either picking or not picking leads to a solution
    return pick || noPick;
}
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
       int currSum=0;
       int ind=0;
       return  helper(ind,arr,sum,currSum);
    }
};



// DP 
bool helper(int ind, vector<int>& arr, int sum, int currSum, vector<vector<int>>& dp) {
    // Base case: if currSum equals the desired sum
    if (currSum == sum) return true;
  
    // If we've gone through the array or current sum exceeds the target sum
    if (ind == arr.size() || currSum > sum) return false;
  
    // If already computed for this index and current sum, return the result
    if (dp[ind][currSum] != -1) return dp[ind][currSum];
  
    // Pick the current element
    bool pick = helper(ind + 1, arr, sum, currSum + arr[ind], dp);
  
    // Do not pick the current element
    bool noPick = helper(ind + 1, arr, sum, currSum, dp);
  
    // Store the result in the dp array and return
    return dp[ind][currSum] = pick || noPick;
}
bool isSubsetSum(vector<int>& arr, int sum) {
    // Initialize the dp array with -1 (uncomputed state)
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    // Start recursion with memoization
    return helper(0, arr, sum, 0, dp);
}
