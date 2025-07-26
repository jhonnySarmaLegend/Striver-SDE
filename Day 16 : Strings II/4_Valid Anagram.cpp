// Link --> https://leetcode.com/problems/valid-anagram/description/

class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[256]={0};
        
        for(auto it:s)arr[it-'0']++;
        for(auto it:t)arr[it-'0']--;

        for(auto it:arr){
            if(it!=0)return false;
        }

        return true;
    }
};
