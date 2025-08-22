/*
  Subset - II | Print all the Unique Subsets || Unique

  Question Link --> https://leetcode.com/problems/subsets-ii/description/
*/

/*
Approach:
At every index, we make a decision whether to pick or not pick the element at that index. This will help us
in generating all possible combinations but does not take care of the duplicates. Hence we will use a set to 
store all the combinations that will discard the duplicates.
*/

// Using Recursion - BRUTE FORCE - 
/*
  Time Complexity: O( 2^n *(k log (x) )). 2^n  for generating every subset and k* log( x)  to insert every combination of average length k in a set of size x. After this, we have to convert the set of combinations back into a list of list /vector of vectors which takes more time.

Space Complexity:  O(2^n * k) to store every subset of average length k. Since we are initially using a set to store the answer another O(2^n *k) is also used.
*/
class Solution {
public:
    void helper(vector<int>& nums, int ind, vector<int> ds, set<vector<int>>& st){
    
    if(ind==nums.size()){
        sort(ds.begin(), ds.end());
        st.insert(ds);
        return;
    }
      //pick - added
      ds.push_back(nums[ind]);
      helper(nums, ind + 1, ds, st);
      //not pick - remove the added one
      ds.pop_back();
      helper(nums, ind + 1, ds, st);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        vector<int> ds;
        helper(nums, 0, ds, st);
        for(auto it:st)ans.push_back(it);
        return ans;
    }
};


// OPTIMAL 
/*
  Let's summarize:-

Sort the input array.Make a recursive function that takes the input array ,the current subset,the current index and 
a list of list/ vector of vectors to contain the answer.

Try to make a subset of size n during the nth recursion call and consider elements from every index while generating the 
combinations. Only pick up elements that are appearing for the first time during a recursion call to avoid duplicates.

Once an element is picked up, move to the next index.The recursion will terminate when the end of array is reached.While 
returning backtrack by removing the last element that was inserted.
*/


void findSubsets(int ind, vector < int > & nums, vector < int > & ds, vector < vector < int >> & ans) {
         ans.push_back(ds);
         for (int i = ind; i < nums.size(); i++) {
            if (i != ind && nums[i] == nums[i - 1]) continue;
            ds.push_back(nums[i]);
            findSubsets(i + 1, nums, ds, ans);
            ds.pop_back();
         }
      }
   public:
      vector < vector < int >> subsetsWithDup(vector < int > & nums) {
         vector < vector < int >> ans;
         vector < int > ds;
         sort(nums.begin(), nums.end());
         findSubsets(0, nums, ds, ans);
         return ans;
      }









// USING BIT MANIPULATION FOR POWER SET
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         set<vector<int>> uniqueSubsets; // Set to store unique subsets

        // Step 1: Sort the array to handle duplicates
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        // Step 2: Generate all subsets using bit manipulation
        for (int i = 0; i < (1 << n); ++i) { // (1 << n) is 2^n
            vector<int> currentSubset;
            for (int j = 0; j < n; ++j) {
                // Check if the j-th bit is set
                if (i & (1 << j)) {
                    currentSubset.push_back(nums[j]);
                }
            }
            // Insert current subset into the set to avoid duplicates
            uniqueSubsets.insert(currentSubset);
        }

        // Convert the set to a vector for the final result
        return vector<vector<int>>(uniqueSubsets.begin(), uniqueSubsets.end());
   
    }
};

