/*
   Question Link --> https://leetcode.com/problems/combination-sum/description/
*/

class Solution {
public:
    void helper(int ind,vector<int> arr,vector<vector<int>> &ans,vector<int> &ds,int target){
        if(ind==arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
       
        //PICK
        if(arr[ind]<=target){
            ds.push_back(arr[ind]);
            helper(ind,arr,ans,ds,target-arr[ind]);//1 element can be picked more than once
            ds.pop_back();// backtrack when not picked remove if added
        }
         
        //NO PICK
        helper(ind+1,arr,ans,ds,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        helper(0,candidates,ans,ds,target);
        return ans;
    }
};

/*
  Time Complexity: O(2^t * k) where t is the target, k is the average length

Reason: Assume if you were not allowed to pick a single element multiple times, every element will have a couple of options: pick or not pick which is 2^n different recursion calls, also assuming that the average length of every combination generated is k. (to put length k data structure into another data structure)

Why not (2^n) but (2^t) (where n is the size of an array)?

Assume that there is 1 and the target you want to reach is 10 so 10 times you can “pick or not pick” an element.

Space Complexity: O(k*x), k is the average length and x is the no. of combinations
*/
