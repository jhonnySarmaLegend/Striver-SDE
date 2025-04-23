/*
  Question Link --> https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
*/

//BRUTE FORCE 
int removeDuplicates(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        nums.assign(s.begin(),s.end()); // reassign after initial declaration
        return nums.size();
    }

//OPTIMAL WAY - Two Pointers
int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=1;
        while(j<nums.size()){
            if(nums[i]!=nums[j]){
                 i++;// moved to next position and value added
                nums[i]=nums[j];
            }
          
            j++;   
        }
        return i+1;
    }

