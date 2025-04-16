/*
 Question Link --> https://leetcode.com/problems/subarray-sum-equals-k/
*/

//BRUTE FORCE SOLUTION - T.C.=O(N^2) , S.C.=O(1)
int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n = arr.size(); // size of the given array.
    int cnt = 0; // Number of subarrays:

    for (int i = 0 ; i < n; i++) { // starting index i
        int sum = 0;
        for (int j = i; j < n; j++) { // ending index j
            // calculate the sum of subarray [i...j]
            // sum of [i..j-1] + arr[j]
            sum += arr[j];

            // Increase the count if sum == k:
            if (sum == k)
                cnt++;
        }
    }
//OPTIMAL SOLUTION - T.C.=O(N) , S.C.=O(N)
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int> mpp;
        int sum=0;//to store prefix sum
        int count=0;
        for(int i=0;i<n;i++){
           sum+=arr[i];
           
           if(sum==k)count++;
           
           int rem=sum-k;
           count+=mpp[rem];

           mpp[sum]++;

        }
        return count;
    }
};
