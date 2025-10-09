/*
   Question Link --> https://leetcode.com/problems/merge-sorted-array/description/
*/

//Leetcode
// Variation -->  nums1 size equals n+m  , and answer will be stored in n+m

class Solution {
public:
   /*
   Input: nums1 = [1,2,3,0,0,0], n = 3, nums2 = [2,5,6], m = 3
   Output: [1,2,2,3,5,6]
   Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
   The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
    */
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int i=n-1,j=0;
        while(i>=0 && j<m){
            if(nums1[i]>nums2[j])swap(nums1[i--],nums2[j++]);
            else break;
        }
        sort(nums1.begin(),nums1.begin()+n);
        sort(nums2.begin(),nums2.end());
        
         for(int i=n; i<m+n; i++){
            nums1[i] = nums2[i-n];
        }
    }
};





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
