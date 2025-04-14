//Majority >  N/2

/*
    Question Link --> https://leetcode.com/problems/majority-element/description/
*/

//T.C. = O(N) , S.C. = O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el=nums[0];
        int c=1;
        for(int i=1;i<nums.size();i++){
            if(c==0){
                el=nums[i];
                c++;
            }
            else if(el==nums[i])c++;
            else c--;
        }
        return el;
    }
};
