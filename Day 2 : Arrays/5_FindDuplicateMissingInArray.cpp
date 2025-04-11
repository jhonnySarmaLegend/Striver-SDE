/*
   Question Link --> https://www.interviewbit.com/problems/repeat-and-missing-number-array/
*/

// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
     vector<int> nums={1,2,3,4,2};
    
           int xr=0;

       for(int i=0;i<nums.size();i++)xr^=nums[i];
       for(int i=1;i<=nums.size();i++)xr^=i;

       int setBit= xr & -xr ;

       int g1=0,g2=0;

       for(int i=0;i<nums.size();i++){
          if(nums[i]&setBit)g1^=nums[i];
          else{
            g2^=nums[i];
          }
       }

       for(int i=1;i<=nums.size();i++){
          if(i&setBit)g1^=i;
          else{
            g2^=i;
          }
       }

       for(auto it:nums){
        if(it==g1)cout<<"{"<<g1<<","<<g2<<"}"; //{2,5}
       }

       cout<<"{"<<g2<<","<<g1<<"}";


    return 0;
}
