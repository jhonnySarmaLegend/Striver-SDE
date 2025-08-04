// Two Pointers


// variation 1--> elements present max once
// Link --> https://leetcode.com/problems/remove-duplicates-from-sorted-array/


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





// variation 1--> elements present max twice
// Link --> https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; // Edge case: empty array
        int i = 0; // Pointer for the result array
        int count = 1; // Count of occurrences of the current element
        int j = 1; // Traversal pointer
        // Traverse the array using a while loop
        while (j < nums.size()) {
            // If the current element is the same as the previous one, increment the count
            if (nums[j] == nums[i]) {
                count++;
            } else {
                // If the current element is different, reset the count
                count = 1;
            }
            // If the count is <= 2, copy the element to the result array
            if (count <= 2) {
                i++;
                nums[i] = nums[j];
            }
            j++; // Move to the next element
        }
        return i + 1; // Return the number of valid elements
        }
    
};
