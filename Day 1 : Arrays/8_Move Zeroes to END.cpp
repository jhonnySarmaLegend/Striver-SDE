// Link --> https://leetcode.com/problems/move-zeroes/description/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // assuming 1st character is always zero
        int i=0,j=0;
        while(j<nums.size()){
         if(nums[j]!=0){
            swap(nums[i],nums[j]);
            i++;
         }
         j++;

        }

    }
};
