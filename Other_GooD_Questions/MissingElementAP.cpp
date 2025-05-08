/*
Link --> https://www.geeksforgeeks.org/problems/missing-element-of-ap2228/1
*/

 int findMissing(vector<int> &arr) {
        // code here
        //T.C. = O(N) , S.C. = O(N)
        vector<int> diff ;
        for(int i=1;i<arr.size();i++){
            diff.push_back(arr[i]-arr[i-1]);
        }
        
        //find r using max element n/2 
        int candidate;
        int count=0;
        for (int num : diff) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
       }
       
       for(int i=0;i<diff.size();i++){
           if(diff[i]!=candidate){
               return arr[i]+candidate;
           }
       }
       //if in ap --> return next element at last
       return arr[arr.size()-1]+candidate;
        
    }
