/*
   Question Link --> https://leetcode.com/problems/next-permutation/description/
*/

// METHOD 1  --> Using inbuilt function
 void nextPermutation(vector<int>& nums) {
    next_permutation(nums.begin(), nums.end());
    }

// METHOD 2 --> Optimal Way
// T.C. = O(3N) , S.C. = O(1)
    void nextPermutation(vector<int>& arr) {
        int n = arr.size(); // size of the array

        // Step 1: Find the break point
        int breakPoint = -1; // break point
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] < arr[i + 1]) {
                // index i is the break point
                breakPoint = i;
                break;
            }
        }

        // If break point does not exist
        if (breakPoint == -1) {
            // reverse the whole array
            reverse(arr.begin(), arr.end());
            return;
        }

        // Step 2: Find the next greater element
        //         and swap it with arr[breakPoint]
        for (int i = n - 1; i > breakPoint; i--) {
            if (arr[i] > arr[breakPoint]) {
                swap(arr[i], arr[breakPoint]);
                break;
            }
        }

        // Step 3: Reverse the right half
        reverse(arr.begin() + breakPoint + 1, arr.end());
    }
