/*
  Question Link --> https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1

  Time Complexity:O(V)

  Space Complexity:O(1)
*/

 vector<int> minPartition(int N) {
    vector<int> ans;
    int rem = N;
    int arr[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};  // Use reverse order for greedy approach
    
    for (int i = 0; i < 10; i++) {
        while (rem >= arr[i]) {
            ans.push_back(arr[i]);
            rem -= arr[i];
        }
    }
    
    return ans;
        
    }
