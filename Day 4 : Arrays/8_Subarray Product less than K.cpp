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
        int count=0,product=1;
        int n=nums.size(); int l=0; int r=0;
        for(int i=0;i<n;i++){
            product*=nums[r];
             while(product>=k && l<=r){
                product=product/nums[l];
                l++;
              }
            count+=(r-l+1); // since l=2,r=4   for 1,2,3,4,5,6, --> [3,4,5] -> subarrays --> [3],[3,4],[3,4,5] = r-l+1=4-2+1=3 subarrays
            r++;
             }
            return count;
        } 
};
