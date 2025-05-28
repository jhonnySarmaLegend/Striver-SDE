/*
   Question Link --> https://leetcode.com/problems/merge-sorted-array/description/
*/

// Method 1
//T.C. = O(N+M) , S.C. = O(1)
void merge(long long arr1[], long long arr2[], int n, int m) {

    //Declare 2 pointers:
    int left = n - 1;
    int right = 0;

   // Arrays already SORTED
   
    //Swap the elements until arr1[left] is
    // smaller than arr2[right]:
    while (left >= 0 && right < m) {
        if (arr1[left] > arr2[right]) {
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else {
            break;
        }
    }

    // Sort arr1[] and arr2[] individually:
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

// METHOD 2 - GAP METHOD
// Variation 2 - length of 2 arrays different
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
       int i = m - 1;       // Index for nums1
    int j = n - 1;       // Index for nums2
    int k = m + n - 1;   // Index for merged array (nums1)

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // Copy any remaining elements from nums2 to nums1
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }

    }
};
