// LINK -->https://leetcode.com/problems/subarray-product-less-than-k/description/


// BRUTE FORCE
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            int prod=1;
            for(int j=i;j<nums.size();j++){
                prod*=nums[j];
                if(prod<k)count++;
                else break;// if subarray sum >k exit inner loop since all elements are positive
            }
        }
        return count;
    }
};


//OPTIMAL
// Two Pointers + Sliding Window
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count=0;
        int prod=1;
        int left=0,right=0;
        while(r<nums.size()){
            prod=prod*nums[right];

            while(prod>=k){
                prod/=numsleft;
                left++;
            }

            count+=right-left+1;
            right++;
        }
        return count;
    }
};
