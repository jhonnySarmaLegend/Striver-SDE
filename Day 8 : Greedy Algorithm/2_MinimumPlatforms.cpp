/*
   Question Link --> https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
*/
//T.C. = O(NlogN)
int findPlatform(vector<int>& arr, vector<int>& dep) {
    int n = arr.size();
    
    // Sort both arrival and departure times
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    
    // Variables to track the maximum platforms needed
    int maxPlatforms = 0;
    int platformsNeeded = 0;
    
    // Using two pointers to traverse the arrival and departure array
    int i = 0, j = 0;
    
    while (i < n && j < n) {
        // If a train arrives before the last one departs
        if (arr[i] <= dep[j]) {
            platformsNeeded++;
            i++;
        } else {
            // Train at platform departs
            platformsNeeded--;
            j++;
        }
        maxPlatforms=max(maxPlatforms,platformsNeeded);
       
    }
    
    return maxPlatforms;
    }
