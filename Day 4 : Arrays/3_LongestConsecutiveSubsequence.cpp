/*
  Question Link --> https://leetcode.com/problems/longest-consecutive-sequence/description/
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxi=0;//  if (nums.empty()) return 0; else would have assigned INT_MIN
        int cnt=0;
        set<int> s(nums.begin(),nums.end());// copy nums to set
        
        for(auto it:s){
            //nums[i] is the starting index
            if(s.find(it-1)==s.end()){
                cnt=1;
                int start=it;
                while(s.find(start+1)!=s.end()){
                  cnt++;
                  start++;
                }
                maxi=max(maxi,cnt);
            }
        }
        return maxi;
    }
};
