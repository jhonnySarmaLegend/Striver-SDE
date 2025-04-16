/*
  Question Link --> https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
*/

// Subarray with sum 0
//T.C. = O(N) , S.C. = O(N)
class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        int n=arr.size();
        unordered_map<int,int> mpp;
        int sum=0;
        int maxi=0; 
        /*Initialization of maxi: Changed maxi = INT_MIN; to maxi = 0;
        to prevent returning INT_MIN for the case with no valid subarrays.*/
        for(int i=0;i<n;i++){
            sum+=arr[i];
            
            if(sum==0)maxi=i+1; // target value found
            
           else if(mpp.find(sum)!=mpp.end())maxi=max(maxi,i-mpp[sum]); // target value already present
            
            else mpp[sum]=i; // target value absent
        }
        return maxi;
    }
};

