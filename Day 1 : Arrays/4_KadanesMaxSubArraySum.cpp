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


//VARiation 2--> Print the subarray
long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {

        if (sum == 0) start = i; // starting index

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }
