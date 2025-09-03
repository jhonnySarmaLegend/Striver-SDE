//Variation 1

// LINK --> https://leetcode.com/problems/spiral-matrix/submissions/1758032987/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result; // Stores the elements in spiral order
        if (matrix.empty() || matrix[0].empty()) {
            return result; // Handle empty matrix
        }
        int left = 0, right = matrix[0].size() - 1; // Column boundaries
        int top = 0, bottom = matrix.size() - 1;    // Row boundaries
        // Traverse the matrix in a spiral order
        while (left <= right && top <= bottom) {
            // Traverse from left to right along the top row
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++; // Move the top boundary down
            // Traverse from top to bottom along the right column
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--; // Move the right boundary left
            // Traverse from right to left along the bottom row
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--; // Move the bottom boundary up
            }
            // Traverse from bottom to top along the left column
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++; // Move the left boundary right
            }
        }
        return result;
    }
};



// VARIATION 2
/*
Here’s a spiral matrix solution in C++ that generates a matrix filled with elements in spiral order. 
This solution uses a simulation approach to traverse the matrix layer by layer in a spiral pattern.
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // Initialize an n x n matrix with zeros
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int value = 1; // Start filling values from 1
        int left = 0, right = n - 1, top = 0, bottom = n - 1;

        // Traverse the matrix in a spiral order
        while (left <= right && top <= bottom) {
            // Move left to right along the top row
            for (int i = left; i <= right; i++) {
                matrix[top][i] = value++;
            }
            top++; // Move the top boundary down

            // Move top to bottom along the right column
            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = value++;
            }
            right--; // Move the right boundary left

            // Move right to left along the bottom row
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    matrix[bottom][i] = value++;
                }
                bottom--; // Move the bottom boundary up
            }

            // Move bottom to top along the left column
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left] = value++;
                }
                left++; // Move the left boundary right
            }
        }

        return matrix;
    }
};

// Example usage:
#include <iostream>
int main() {
    Solution sol;
    vector<vector<int>> result = sol.generateMatrix(3);

    // Print the generated matrix
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
