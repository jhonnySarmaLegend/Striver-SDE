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


/*
For x = 18 (which is 10010 in binary), the expression -x computes to -18 (which is 01110 in binary when considering signs in a binary representation).
x & -x then computes 10010 & 01110 = 00010, isolating the first set bit which is 2.

~x=-(x+1) , x=integer
~19=20
~(-19)= - (-19+1)=18



To convert the decimal number -18 into its binary representation using two's complement, you can follow these steps:

Convert the absolute value (18) to binary.
Find the two's complement of the binary representation of 18.
Step 1: Convert 18 to Binary
The binary representation of 18 is derived as follows:

18 divided by 2 gives:
18 mod 2 = 0 (least significant bit)
9 mod 2 = 1
4 mod 2 = 0
2 mod 2 = 0
1 mod 2 = 1
Reading the remainders from bottom to top, 18 in binary is 10010.

Step 2: Prepare for Two's Complement
Now, you need to represent 18 in a fixed number of bits. For this example, we'll use an 8-bit representation:

00010010 for 18.
Step 3: Invert the Bits
To find the two's complement, you need to invert all the bits of 18:

00010010 inverted becomes 11101101.
Step 4: Add 1
Now add 1 to the inverted binary:

text

  11101101
+         1
-----------
  11101110
Therefore, the binary representation of -18 in two's complement format is 11101110 when using an 8-bit system
*/
