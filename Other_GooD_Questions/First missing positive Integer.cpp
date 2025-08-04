//  Link --> https://leetcode.com/problems/first-missing-positive/description/



// BRUTE FORCE
// T.C.= O(N) , S.C.=O(2N)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
         // Step 1: Store unique positive elements
        set<int> uniquePos;
        for (int num : nums) {
            if (num > 0) {
                uniquePos.insert(num); // Only unique positive elements are added
            }
        }
        // Step 2: Convert the set to a sorted vector
        vector<int> pos(uniquePos.begin(), uniquePos.end());
        // Step 3: Find the first missing positive integer
        int n = pos.size();
        for (int i = 0; i < n; i++) {
            if (pos[i] != i + 1) {
                return i + 1; // The smallest missing positive integer
            }
        }
        // If all positive integers from 1 to n are present, return n + 1
        return n + 1;

    }
};




// cyclic sort--> https://www.youtube.com/watch?v=YvksaZhYYAk


class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int n = arr.size();
    // Cyclic Sort: Place each positive integer in its correct position [for arr in range 1 to n]
    for (int i = 0; i < n; i++) {
        while (arr[i] > 0 && arr[i] <= n && arr[i] != arr[arr[i] - 1]) {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }
    // Find the first missing positive integer
    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    // If all numbers from 1 to n are present, return n + 1
    return n + 1;
    }
};
