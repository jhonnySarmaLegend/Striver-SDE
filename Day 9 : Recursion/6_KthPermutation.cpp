/*
 https://leetcode.com/problems/permutation-sequence/description/

 The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

 

Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"
*/


// 1) Using Inbuilt functions
// 
    string getPermutation(int n, int k) {
        string nums; // S.C.=O(N)
        for(int i=1;i<=n;i++)nums+=to_string(i);
        for(int i=1;i<k;i++)next_permutation(nums.begin(),nums.end());// T.C. = O(k*N)
        return nums;
    }

// BRUTE FORCE Recursion
/*
Time complexity: O(N! * N) +O(N! Log N!)

Reason:  The recursion takes O(N!)  time because we generate every possible permutation and
another O(N)  time is required to make a deep copy and store every sequence in the data structure. 
Also, O(N! Log N!)  time required to sort the data structure

Space complexity: O(N) 

Reason: Result stored in a vector, we are auxiliary space taken by recursion
*/
    //function to generate all possible permutations of a string
    void permutationHelper(string & s, int index, vector < string > & res) {
      if (index == s.size()) {
        res.push_back(s);
        return;
      }
      for (int i = index; i < s.size(); i++) {
        swap(s[i], s[index]);
        permutationHelper(s, index + 1, res);
        swap(s[i], s[index]);
      }
    }

  string getPermutation(int n, int k) {
    string s;
    vector < string > res;
    //create string
    for (int i = 1; i <= n; i++) {
      s.push_back(i + '0');
    }
    permutationHelper(s, 0, res);
    //sort the generated permutations
    sort(res.begin(), res.end());
    //make k 0-based indexed to point to kth sequence
    auto it = res.begin() + (k - 1);
    return *it;
  }
};
