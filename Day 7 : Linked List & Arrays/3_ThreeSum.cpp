//Question Link --> https://leetcode.com/problems/3sum/description/
// Variation where nums[i], nums[j],nums[k] cannot repeat
/*
   Here This test cases will fail
   nums =
   [-2,0,1,1,2]

   Use Testcase
   Output
   [[-2,0,2]]
   Expected
   [[-2,0,2],[-2,1,1]]
*/
vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
             if(i!=0 && nums[i]==nums[i-1])continue;

             int j=i+1;
             int k=n-1;
           
             while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;k--;
                     while(j<k && nums[j]==nums[j+1])j++;
                     while(j<k && nums[k]==nums[k-1])k--;
                }
                else if(sum>0)k--;
                else j++; // sum<0
             }          
        }
        return ans;
    }



// VARIATION 2 where same element usage twicw is allowed , but triplets should be unique
// {1,1,-2} allowed but  {1,1,-2} not LLOWED AGAIN

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
             if(i!=0 && nums[i]==nums[i-1])continue;

             int j=i+1;
             int k=n-1;
           
             while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    ans.insert(temp);
                    j++;k--;
                    //  while(j<k && nums[j]==nums[j+1])j++;
                    //  while(j<k && nums[k]==nums[k-1])k--;
                }
                else if(sum>0)k--;
                else j++; // sum<0
             }          
        }
        vector<vector<int>> ansFinal(ans.begin(),ans.end());
        return ansFinal;
    }

