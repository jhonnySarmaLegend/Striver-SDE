/*
    Question Link --> https://leetcode.com/problems/maximum-subarray/description/
*/

// T.C. = O(N) , S.C. = O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(sum<=0)sum=0;//only for +ve sum
            sum+=nums[i];
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};
