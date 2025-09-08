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
        if (k <= 1) return 0;
        int n=nums.size(); int l=0; int r=0;  int product=1; int sum=0;
        for(int i=0;i<n;i++){
            product*=nums[r];
             while(product>=k && l<=r){
                product=product/nums[l];
                l++;
              }
            sum+=(r-l+1);
            r++;
             }
            return sum;
        } 
};
