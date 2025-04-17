/*
  Question Link --> https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*/


// METHOD 1 - using hashmap
class Solution {
public:
// T.C. = O(N^2) , S.C. = O(N)
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            int hash[256]={0};
            for(int j=i;j<n;j++){
                if(hash[s[j]]==1)break;
                maxi=max(maxi,j-i+1);
                hash[s[j]]=1;
            }
        }
        return maxi;
    }
};

// METHOD 2 - using set
class Solution {
public:
// T.C. = O(N) , S.C. = O(256)
    int lengthOfLongestSubstring(string s) {
      vector < int > mpp(256, -1);
      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mpp[s[right]] != -1)
          left = max(mpp[s[right]] + 1, left);
        
        mpp[s[right]] = right;
        
        len = max(len, right - left + 1);
        right++;
      }
      return len;
    }
};
