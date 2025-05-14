//Question Link --> 

// Bit Manipulation
// T.C. =O(N) , S.C.=O(1)
  int singleNonDuplicate(vector<int>& nums) {
        int xr=0;
        for(auto it: nums)xr^=it;
        return xr;
    }

//USING Binary Search 
//T.C. =O(LogN) , S.C.=O(1)
 int singleNonDuplicate(vector<int>& arr) {
int n = arr.size(); //size of the array.

    //Edge cases:
    if (n == 1) return arr[0]; // arr size=1
    if (arr[0] != arr[1]) return arr[0];// 1st element
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];//last element

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if arr[mid] is the single element:
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
            return arr[mid];
        }

        //we are in the left:
        // (even,odd) mid at odd || mid at even
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1])
                || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            //eliminate the left half:
            low = mid + 1;
        }
        //we are in the right:
        else {
            //eliminate the right half:
            high = mid - 1;
        }
    }

    // dummy return statement:
    return -1;
    }




//Alternate Code
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int hei = nums.size() - 2;
        
        while(low <= hei){
            int mid = (low + hei) / 2;
            if(nums[mid] == nums[mid^1]){
                low = mid + 1;
            }else{
                hei = mid - 1;
            }
        }
        
        return nums[low];
    }
