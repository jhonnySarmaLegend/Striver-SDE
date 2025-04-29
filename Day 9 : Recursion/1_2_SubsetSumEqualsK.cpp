/*
  Question Id--> https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
*/

// Using Rec. O(2^n) but need to use DP

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
        int n=arr.size();
       return  helper(0,arr,n,sum,currSum);
    }
