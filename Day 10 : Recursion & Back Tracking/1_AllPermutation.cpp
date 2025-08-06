// Question Link --> https://leetcode.com/problems/permutations/description/

// Using Inbuilt function
 vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>> ans;
        vector<int> arr(nums.begin(),nums.end());
        ans.push_back(arr);
        next_permutation(arr.begin(),arr.end());
        while(arr!=nums){
           ans.push_back(arr);
        next_permutation(arr.begin(),arr.end());
        }
        return ans;
    }


//BRUTE FORCE - RECURSION
/*
Time Complexity:  N! x N

Space Complexity:  O(N)
*/
  private:
    void recurPermute(vector < int > & ds, vector < int > & nums, vector < vector < int >> & ans, int freq[]) {
      if (ds.size() == nums.size()) {
        ans.push_back(ds);
        return;
      }
      for (int i = 0; i < nums.size(); i++) {
        if (!freq[i]) {
          ds.push_back(nums[i]);
          freq[i] = 1;
          recurPermute(ds, nums, ans, freq);
          freq[i] = 0;
          ds.pop_back();
        }
      }
    }
  public:
    vector < vector < int >> permute(vector < int > & nums) {
      vector < vector < int >> ans;
      vector < int > ds;
      int freq[nums.size()];
      for (int i = 0; i < nums.size(); i++) freq[i] = 0;
      recurPermute(ds, nums, ans, freq);
      return ans;
    }


//  OPTIMAL way 
/*
Time Complexity: O(N! X N)

Space Complexity: O(1)*/
    void recurPermute(int index, vector < int > & nums, vector < vector < int >> & ans) {
      if (index == nums.size()) {
        ans.push_back(nums);
        return;
      }
      for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        recurPermute(index + 1, nums, ans);
        swap(nums[index], nums[i]);// reswap or Backtrack
      }
    }
  public:
    vector < vector < int >> permute(vector < int > & nums) {
      vector < vector < int >> ans;
      recurPermute(0, nums, ans);
      return ans;
    }

