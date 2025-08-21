// Link -->https://leetcode.com/problems/container-with-most-water/description/

// BRUTE FORCE --> TLE   --> tc=O(N^2)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxWater=INT_MIN;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int width = j-i;
                int currH = min(height[j],height[i]);
                int waterStored=currH*width;
                maxWater=max(maxWater,waterStored);
            }
        }
        return maxWater;
    }
};

//OPTIMAL  --> Two pointer --> O(N)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxWater=INT_MIN;
        int left=0,right=n-1;
        while(left<right){
            int width=right-left;
            int currH=min(height[left],height[right]);
            int waterStored=width*currH;
            maxWater=max(maxWater,waterStored);
            //moving the min height and trying to maximize it
            if(height[left]<height[right]) left++;
            else    right--;
        }
        return maxWater;
    }
};

