/*
Problem Statement: Given a row-wise sorted matrix of size MXN, where M is no. of rows and 
N is no. of columns, find the median in the given matrix.

Note: MXN is odd.

The extremely naive approach is to use a linear array/list to store the elements of the 
given matrix. Now, we will sort the list and return the middle element.
*/
/*
Time Complexity: O(MXN) + O(MXN(log(MXN))), where M = number of row in the given matrix, 
N = number of columns in the given matrix

Reason: At first, we are traversing the matrix to copy the elements. This takes O(MXN)
time complexity. Then we are sorting the linear array of size (MXN), that takes O(MXN(log(MXN))) time complexity

Space Complexity: O(MXN) as we are using a temporary list to store the elements of the matrix.
*/

int median(vector<vector<int>> &matrix, int m, int n) {
    vector<int> lst;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            lst.push_back(matrix[i][j]);
     } }
    sort(lst.begin(), lst.end());
    return lst[(m * n) / 2];
}


//OPTIMAL

int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int x) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cnt += upperBound(matrix[i], x, n);
    }
    return cnt;
}

int median(vector<vector<int>> &matrix, int m, int n) {
    int low = INT_MAX, high = INT_MIN;

    //point low and high to right elements:
    for (int i = 0; i < m; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n - 1]);
    }

    int req = (n * m) / 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(matrix, m, n, mid);
        if (smallEqual <= req) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}
