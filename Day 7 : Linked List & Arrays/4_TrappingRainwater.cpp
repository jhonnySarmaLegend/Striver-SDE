/*
  Question Link --> https://leetcode.com/problems/trapping-rain-water/description/
*/
//Good Solution --> TLE
// T.C. = O(N^2) , S.C. = O(1) 
class Solution {
public:
    int trap(vector<int>& height) {
        //water trapped = min(maxL,maxR)-height[i]
        int n=height.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int maxL=0,maxR=0;
           
           //for(maxleft)
           int j=i-1;
           while(j>=0){
            maxL=max(maxL,height[j]);
            j--;
           }

           //for(maxRight)
           j=i+1;
           while(j<n){
            maxR=max(maxR,height[j]);
            j++;
           }
           
           int water=min(maxL,maxR)-height[i];
           if(water>0)ans+=water;
        }
        return ans;  
    }
};

// OPTIMAL SOLUTION --> 2 POINTERS
// T.C.=O(N) ,  S.C. = O(1) 
int trap(vector<int>& height){
        int n=height.size();
        int ans=0;
        int left=0,right=n-1;
        int maxL=height[left],maxR=height[right];
        while(left<right){
            //looking for min value on left and right of to calculate further
            if(maxL<=maxR){
                left++;
                if(maxL<height[left])maxL=height[left];
                else  ans+=maxL-height[left];
            }
            else{
                right--;
                if(maxR<height[right])maxR=height[right];
                else  ans+=maxR-height[right];
            } 
        }
        return ans;
 }
