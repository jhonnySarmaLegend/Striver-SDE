// Link --> https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/
class Solution {
public:
    int maxDepth(string s) {
        int maxi=0;// minimum possible ans is 0
        int count=0;
        for(auto c:s){
            if(c=='(')count++;
            else if(c==')')count--;
            else continue;

            maxi=max(maxi,count);
        }
        return maxi;

    }
};
