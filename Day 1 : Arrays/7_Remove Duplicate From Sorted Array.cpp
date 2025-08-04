// Link --> https://leetcode.com/problems/remove-duplicates-from-sorted-array/


// Two Pointers
class Solution {
public:
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
};
