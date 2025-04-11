/*
    Question Link --> https://leetcode.com/problems/find-the-duplicate-number/description/
*/

// Easy Sorting --> T.C. O(NLOGN) , S.C. = O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) return nums[i];
        }
        return 0;
    }
};

// Method 2 --> using Map --> T.C. = O(N) , S.C. = O(N)
class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        std::unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
            if (counts[num] > 1) {
                return num;
            }
        }
        return -1; // Should not reach here based on problem constraints
    }
};

//Method 3 
int findDuplicate(vector < int > & nums) {
  int slow = nums[0];
  int fast = nums[0];
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);
  fast = nums[0];
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }
  return slow;
}

/* //This will work but fail for cases where input array like [3,3,3,3]
  class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       // Extension of missing & repeating
       /*
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
        if(it==g1)return g1;
       }

       return g2;
*/
      sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if((nums[i]^nums[i-1])==0) return nums[i];
        }
        return 0;
    }
};
*/
