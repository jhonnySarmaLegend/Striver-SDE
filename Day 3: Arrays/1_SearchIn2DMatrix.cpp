/*
   Question Link --> https://leetcode.com/problems/search-a-2d-matrix/description/
*/


// METHOD 1 --> SEARCH SPACE REDUCTION 
//  T.C. = O(M+N) , S.C. =O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false; // Check for empty matrix
        int m = matrix[0].size(); // Correctly retrieve the number of columns

        int row = 0; // Start from the top row
        int col = m - 1; // Start from the last column

        while (row < n && col >= 0) { // Loop while within matrix bounds
            if (matrix[row][col] > target) {
                col--; // Move left
            } else if (matrix[row][col] < target) {
                row++; // Move down
            } else {
                return true; // Found the target
            }
        }

        return false; // Target not found
    }
};




//METHOD 2 --> searching in rows where it falls in range using B.S.
class Solution {
public:
   
bool binarySearch(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    int low = 0, high = n - 1;

    // Perform the steps:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return true;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m=matrix[0].size();
       for(int i=0;i<n;i++){
          if(target>=matrix[i][0] && target<=matrix[i][m-1]){
            // int j=0;
            // while(j<m){
            //     if(matrix[i][j]==target)return true;
            //     j++;
            
             return binarySearch(matrix[i], target);
             }
          }
       //}
       return false;
    }
};




// METHOD 3 --> USING BINARY SEARCH by Flatteining the 2D Array into 1D Array
// T.C. =  O(log(NxM)) , S.C. = O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    //apply binary search:
    int low = 0, high = n * m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / m, col = mid % m;
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}



