// Link --> https://leetcode.com/problems/longest-common-prefix/description/

class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int n=s.size();

        sort(s.begin(),s.end());

        string ans="";        
        string first=s[0],last=s[n-1];

        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]==last[i]){
                 ans+=first[i];
            }
            else break;
        }
        return ans;
    }
};
