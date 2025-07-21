//Question Link --> https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

//BRUTE FORCE --> T.C. =O((M+N)log(M+N))
int kthElement(vector<int> &a, vector<int> &b, int k) {
    vector<int> arr;
    // add the elements of array a
    for(auto i: a)arr.push_back(i);
    // add the elements of array a
    for(auto i: b)arr.push_back(i);
    // sort the merged array
    sort(arr.begin(), arr.end());
    // return the kth element
    return arr[k-1];
}


//Better - using Min Heap - Priority Queue
 int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        priority_queue<int,vector<int>, greater<int>> pq;
        
        for(auto it:a)pq.push(it);
        
        for(auto it:b)pq.push(it);
        
        k--;
        
        while(k--){
            pq.pop();
        }
        
        return pq.top();
    }


//Merge two sorted array --> then find arr[k-1]--> T.C.= O(M+N) 


//OPTIMAL - B.S.
/*
Time Complexity: O(log(min(m, n))), where m and n are the sizes of two given arrays.
Reason: We are applying binary search on the range [max(0, k-n2), min(k, n1)]. The range length <= min(m, n).

Space Complexity: O(1), as we are not using any extra space to solve this problem.
*/
int kthElement(vector<int> &a, vector<int>& b, int m, int n, int k) {
    if (m > n) return kthElement(b, a, n, m, k);

    int left = k; //length of left half

    //apply binary search:
    int low = max(0, k - n), high = min(k, m);
    while (low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        //calculate l1, l2, r1 and r2;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < m) r1 = a[mid1];
        if (mid2 < n) r2 = b[mid2];
        if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }

        //eliminate the halves:
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0; //dummy statement

}
