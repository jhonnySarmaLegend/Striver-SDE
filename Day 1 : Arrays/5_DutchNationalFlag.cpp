// SORT Array Of 0's , 1's & 2's
/*
   Question Link --> https://leetcode.com/problems/sort-colors/description/
*/
//T.C. = O(N) , S.C. = O(1)

class Solution {
public:
    void sortColors(vector<int>& arr) {
        int left=0,mid=0;
        int right=arr.size()-1;

        while(mid<=right){
            if(arr[mid]==0){
                swap(arr[mid++],arr[left++]);
            }
            else if(arr[mid]==1)mid++;
            else{ //==2
                swap(arr[mid],arr[right--]);
            }
        }
    }
};
