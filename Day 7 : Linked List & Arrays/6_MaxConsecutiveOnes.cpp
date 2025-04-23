/* 
  Question Link --> https://leetcode.com/problems/max-consecutive-ones/description/
*/
 // T.C. = O(N) , S.C. = O(1)
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0,maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)count=0;

            else count++;

            maxi=max(maxi,count);
        }
        return maxi;
    }
