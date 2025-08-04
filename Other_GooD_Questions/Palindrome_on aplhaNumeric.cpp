//Link --> https://leetcode.com/problems/valid-palindrome/description/

class Solution {
public:
    bool isPalindrome(string s) {
         string str="";
         for(char it:s)//alpha numeric
            if(it>='A' && it<='Z'  || it>='a' && it<='z'   || (it >= '0' && it <= '9'))str+=tolower(it);
         
        //  string srev=str;
        //  reverse(srev.begin(),srev.end());
        //  return srev==str;
        int i=0,j=str.size()-1;
        while(i<=j){
           if(str[i]!=str[j])return false;
           else{
            i++;j--;
           }
        }
            
        return true; 
    }
};
