/*
  Question Link --> https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
*/

// Subarray with sum 0
//T.C. = O(N) , S.C. = O(N)
class Solution {
  public:
    int maxLength(vector<int>& arr) {
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
            
            // rem find --> k=0 , rem=sum-k=sum-0=sum
            if(mpp.find(sum)!=mpp.end())maxi=max(maxi,i-mpp[sum]); // target value already present
            
            if(mpp.find(sum)==mpp.end())mpp[sum]=i; // target value absent
        }
        return maxi;
    }
};

//Subarray with sum = k
int getLongestSubarray(vector<int>& a, int k) {
    int n = a.size(); // size of the array.

    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of the remaining part i.e., x-k:
        int rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}
